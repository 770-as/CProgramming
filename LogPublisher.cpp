#include <ctime>
#include <iostream>
#include <iomanip>

const int BUFFER_SIZE=80;
char buffer[BUFFER_SIZE];

class LogPublisher {
public:
    virtual ~LogPublisher()=default;
    virtual void Write(const std::string& data)=0;
};
class ConcreteLogPublisher : public LogPublisher {
private:
    std::string filename;//renamed for filename for clarity
public:
    ConcreteLogPublisher(const std::string& name) : filename(name) {
        std::cout << "Initializing the file" << filename << std::endl;
    }
    void Write(const std::string& data) override {
        std::cout << "Core writing" << data.length() << std::endl;//std::string::length is a function and requires parentheses
    }
};   
class BaseDecoratorLogPublisher : public LogPublisher {
protected:
    std::unique_ptr<LogPublisher> wrappedLog;
public:
    BaseDecoratorLogPublisher(std::unique_ptr<LogPublisher> log) : wrappedLog(std::move(log)) {}
    void Write(const std::string& data) override {
        wrappedLog->Write(data);
    }   
};
class EncryptionLogger : public BaseDecoratorLogPublisher {
public:
    EncryptionLogger(std::unique_ptr<LogPublisher> log) : BaseDecoratorLogPublisher(std::move(log)) {}
    void Write(const std::string& data) override {
        std::string encryptedData = "AES_CIPHER["+data+"]";
        wrappedLog->Write(encryptedData);
    }
};
class CompressionLogger : public BaseDecoratorLogPublisher {
public:
    CompressionLogger(std::unique_ptr<LogPublisher> log) : BaseDecoratorLogPublisher(std::move(log)) {}
    void Write(const std::string& data) override {
        std::string compressedData= "GZIP_BLOCK ["+data+"]";
        wrappedLog->Write(compressedData);
    }
};
class TimestampLogger : public BaseDecoratorLogPublisher {
public:
    TimestampLogger(std::unique_ptr<LogPublisher> log) : BaseDecoratorLogPublisher(std::move(log)) {}
    void Write(const std::string& data) override {
        std::time_t currentTime = std::time(nullptr);//std::time() takes a pointer to a time_t object and returns the current time.
        std::tm* localTimeStruct = std::localtime(&currentTime);//that struct is necessary because fields are of different kind
        if (localTimeStruct == nullptr) {
            std::cerr << "Error: Failed to convert time to local structure." << std::endl;      
            return;
        }
        std::strftime(buffer, BUFFER_SIZE, "%Y-%m-%d %H:%M:%S", localTimeStruct);//
        std::string timestamp= "[" +std::string(buffer)+ "]" + data;
        wrappedLog->Write(timestamp);
    }
}
int main() {
    std::cout << "--- Logging System Startup ---" << std::endl;

    // We chain the decorators from innermost (File) to outermost (Timestamp)
    // Data flow: Data -> Timestamp -> Compression -> Encryption -> File
    
    // 1. Start with the base component (FileWriter)
    std::unique_ptr<LogPublisher> baseFile = 
        std::make_unique<ConcreteLogPublisher>("secure_log.dat");

    // 2. Add Encryption on top of the base
    std::unique_ptr<LogPublisher> encryptedLog              
        std::make_unique<EncryptionLogger>(std::move(baseFile));

    // 3. Add Compression on top of the encryption
    std::unique_ptr<LogPublisher> compressedEncryptedLog = 
        std::make_unique<CompressionLogger>(std::move(encryptedLog));

    // 4. Add Timestamp as the outermost layer (runs first)
    std::unique_ptr<LogPublisher> finalLog = 
        std::make_unique<TimestampLogger>(std::move(compressedEncryptedLog));

    // --- Execute the Write Operation ---
    std::cout << "\n--- Writing Log Data ---\n";
    finalLog->Write("System is running normally.");
    return 0;
}
/*std::make_unique is a utility function template introduced in C++14 that simplifies the correct and safe creation of objects wrapped 
within a std::unique_ptr. It is the preferred way to allocate dynamic memory for a single object and immediately assign ownership of 
that memory to a std::unique_ptr.
While std::make_unique achieves the same result as direct use of new, it offers three key benefits:
A. Exception Safety (The Primary Reason). Using direct new can lead to a subtle but serious bug if an exception is thrown during 
an intermediate function ca. */