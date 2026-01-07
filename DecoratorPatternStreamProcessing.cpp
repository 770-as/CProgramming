class IFileStream {
public:
    virtual ~IFileStream()=default;
    virtual void Write(const std::string& data) = 0;
    virtual void Flush() = 0;
};
//This is the abstract base class that defines the common contract for all elements
//It is the base operation that writes raw data to the underlying disk. It doesn't know anything about compression or encryption.
/*This is the initializer list which executes before the code inside the curly 
//braces of the constructor body. It initializes the private member variable _fileName directly with the value of the argument name. 
//For class members using the initialized list is the most efficient way to set their initial value. It avoids calling the default      
//constructor on _filename followed by a separate assignment ensuring the object is constructed correctly in one step. 
For class members, using the initalizer list is the most efficient way to set their initial value. It avoids calling the default 
constructor on _filename followed by a separate assignment ensuring the object is constructed correctly in one step. */
class FileWriter : public IFileStream {
private:
    std::string _fileName;
public:
    FileWriter(const std::string& name) : _fileName(name) { 
        std::cout << "[Core] Initializing write for file: " << _fileName << std::endl;
    }
//a reference to std::string named name const ensures the function can't modify the original string passed to it and using a reference 
//avoids making an expensive copy of the string. 
    void Write(const std::string& data) override {
        std::cout << "[Core] Writing " << data.length() << " raw bytes to disk. " << std::endl;
    }
    void Flush() override {
        std::cout << "[Core] Disk buffer flushed." << std::endl;
    }
};
class StreamDecorator : public IFileStream {
protected:
    // Reference to the object being wrapped (owned by the decorator)
    std::unique_ptr<IFileStream> _wrappedStream;
public:
    StreamDecorator(std::unique_ptr<IFileStream> stream)
        : _wrappedStream(std::move(stream)) {}
    // Default delegation: Passes the call to the wrapped object.
    void Write(const std::string& data) override {
        _wrappedStream->Write(data);
    }  
    void Flush() override {
        _wrappedStream->Flush();
    }
};
class CompressionDecorator : public StreamDecorator {
public:
    CompressionDecorator(std::unique_ptr<IFileStream> stream)
        : StreamDecorator(std::move(stream)) {}
    void Write(const std::string& data) override {
        std::cout << "[Decorator] Compressing data..." << std::endl;
        // Simulate compression: Data size is reduced
        std::string compressedData = data + "_compressed"; 
        _wrappedStream->Write(compressedData);
        std::cout << "[Decorator] Compression finished." << std::endl;
    }
};





class EncryptionDecorator : public StreamDecorator {
public:
    EncryptionDecorator(std::unique_ptr<IFileStream> stream)
        : StreamDecorator(std::move(stream)) {}

    void Write(const std::string& data) override {
        std::cout << "[Decorator] Encrypting data..." << std::endl;
        // Simulate encryption: Data is scrambled
        std::string encryptedData = "AES_(" + data + ")_cipher";
        _wrappedStream->Write(encryptedData);
        std::cout << "[Decorator] Encryption finished." << std::endl;
    }
};


void demonstrate_decorator() {
    const std::string logData = "System startup sequence successful.";

    // Scenario 1: Only Compression
    // Data flow: Data -> Compress -> File
    std::unique_ptr<IFileStream> onlyCompressed = 
        std::make_unique<CompressionDecorator>(
            std::make_unique<FileWriter>("log_1.dat")
        );
    
    std::cout << "\n--- Scenario 1: Compression Only ---" << std::endl;
    onlyCompressed->Write(logData);
    // Scenario 2: Encrypt THEN Compress
    // Data flow: Data -> Encrypt -> Compress -> File
    std::unique_ptr<IFileStream> encryptedAndCompressed = 
        std::make_unique<CompressionDecorator>(    // Outermost layer: runs last before core
            std::make_unique<EncryptionDecorator>( // Middle layer
                std::make_unique<FileWriter>("log_2.dat") // Innermost layer: core operation
            )
        );
    
    std::cout << "\n--- Scenario 2: Encrypt (Inner) then Compress (Outer) ---" << std::endl;
    encryptedAndCompressed->Write(logData);
    
    // The sequence in Scenario 2 is:
    // 1. Write() called on CompressionDecorator.
    // 2. CompressionDecorator encrypts the data.
    // 3. CompressionDecorator calls Write() on FileWriter.
}
int main() {
    demonstrate_decorator();
    return 0;
}

