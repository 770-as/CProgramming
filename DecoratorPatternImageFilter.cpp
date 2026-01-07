
/*Create one base class coffee two classes inherit from coffee like Espresso and Decaf then one base class decorator two decorator
classes inherit from that base decorator. The decorator class is made to wrap with it the methods   
The function in the base class must be declared with the virtual keyword. This tells the compiler to use the vtable (virtual table) mechanism, 
allowing the program to determine which version of the function (base or derived) to call at runtime based on the actual object type.
Example: virtual double Process() const;
The function in the derived class must have an identical signature to the virtual function in the base class. The signature includes the 
function name and the parameter list (order and types).
Example: If the base function is virtual double Process(int x, bool y); the derived function must be double Process(int x, bool y) override;
3. Must Have the Same Return Type
The function must have the same return type as the base function.
Note: The only exception to this rule is called Covariant Return Types, which allows the derived function to return a pointer or reference 
to a derived class if the base function returns a pointer or reference to the base class. For simple types (like double, int, std::string), 
they must be identical.
std::move(image) in C++ is a core component of the C++ Move Semantics feature, introduced in C++11.
It does not actually move any data; instead, it is a static cast that converts its argument (image) into an rvalue reference (specifically, an unnamed rvalue reference of type T&&).
Its primary purpose is to signal that the object's resources can be safely stolen from its current location, enabling optimization 
through move operations.
It takes the variable image (an lvalue, which is a named variable).
It casts this variable to an rvalue reference (T&&). An rvalue reference is typically used to refer to a temporary object (an rvalue) 
that won't be used again.
By casting the named variable (image) to an rvalue reference, you are falsely telling the compiler that image is a temporary object 
whose lifetime is about to end.
It takes the variable image (an lvalue, which is a named variable).
It casts this variable to an rvalue reference (T&&). An rvalue reference is typically used to refer to a temporary object (an rvalue) that won't be used again.
    By casting the named variable (image) to an rvalue reference, you are falsely telling the compiler that image is a temporary object whose lifetime is about to end.
2. Triggering the Move Constructor/Assignment
This rvalue reference then allows the compiler to choose the move constructor or move assignment operator of the target class (e.g., std::unique_ptr or std::string) instead of the more expensive copy constructor or copy assignment operator.*/
//On a basic image, you could add filters to change the color at runtime. To obtain some color, you must respect some order of 
//filters applied. Adding a new filter is independent from other filters. The entire chain of filters from the base image to the 
//final decorated image must be treated as a single Image object so the main rendering function only needs to call one process() 
//method. The base class is image from which many images derive. The base decorator is filter from which many filters derive. 


class Image {
public:
    virtual ~Image()= default;
    virtual double Process()=0;
    virtual double Color()=0;
    virtual std::string Intensity()=0;
};                                               
class RawImage : public Image {
private: 
    double _baseSize;
public:
    RawImage(double size) : _baseSize(size) {}
    double Process() const override {
        return _baseSize;//780x780 returns a compiler error
    }
    std::string GetColorMode() const override {
        return "RGB_Full";
    }
    double GetIntensityValue() const override {
        return 100.0; //Base intensity value
    }
};
class ImageFilterDecorator : public Image {
    protected:
    std::unique_ptr<Image> _wrappedImage;//We own and manage the lifetime of the wrapped image, unique_ptr is safer.
    // A pointer to the object being decorated (a Coffee or another Decorator)
    //Image* _wrappedImage;
public:
    // Constructor takes the object to be wrapped
    ImageFilterDecorator(std::unique_ptr<Image> image) : _wrappedImage(std::move(image)) {} 
    double Process() const override {
        return _wrappedImage->Process();
    }
    std::string GetColorMode() const override {
        return _wrappedImage->GetColorMode();
    }
    double GetIntensityValue() const override {
        return _wrappedImage->GetIntensityValue();
    }
    // Default implementations simply delegate to the wrapped object
};
class GrayscaleFilter : public ImageFilterDecorator {
    public:
        GrayscaleFilter(std::unique_ptr<Image> image) : ImageFilterDecorator(std::move(image)) {}
        double Process() const override {
            return ImageFilterDecorator::Process() + 5.0;
        }
        std::string GetColorMode() const override {
            return ImageFilterDecorator::GetColorMode() " + Grayscale";
        }
        double GetIntensityValue() const override {
            return ImageFilterDecorator::GetIntensityValue() - 10;        
        }
};
class BlurFilter : public ImageFilterDecorator {
    public:
        BlurFilter(std::unique_ptr<Image> image) : ImageFilterDecorator(std::move(image)) {}
        double Process() const override {
            return ImageFilterDecorator::Process() + 8.0;
        }
        std::string GetColorMode() const override {
            return ImageFilterDecorator::GetColorMode() + " + The color is blurry";
        }
        double GetIntensityValue() {
            return ImageFilterDecorator::GetIntensityValue() - 5.0;
        }
};

int main() {
    std::unique_ptr<Image> baseImage = std::make_unique<RawImage>(780.0);    
    std::cout << "---Base Image (RGB Full) ---" << std::endl;

    std::cout << "Color Mode: " << baseImage->GetColorMode() << std::endl;
    std::cout << "Final Cost: " << baseImage->Process() << std::endl;
    std::cout << "Intensity: " << baseImage->GetIntensityValue() << std::endl;

    // 2. Wrap the image with a Grayscale Filter (Decorator A)
    // The GrayscaleFilter now owns the baseImage
    std::unique_ptr<Image> grayImage = std::make_unique<GrayscaleFilter>(std::move(baseImage));
    
    std::cout << "\n--- Grayscale Filter Applied ---" << std::endl;
    std::cout << "Color Mode: " << grayImage->GetColorMode() << std::endl;
    std::cout << "Final Cost: " << grayImage->Process() << " (780.0 + 5.0)" << std::endl;
    std::cout << "Intensity: " << grayImage->GetIntensityValue() << " (100.0 - 10.0)" << std::endl;


    // 3. Wrap the Grayscale image with a Blur Filter (Decorator B)
    // The BlurFilter now owns the grayImage (and transitively the RawImage)
    std::unique_ptr<Image> blurredGrayImage = std::make_unique<BlurFilter>(std::move(grayImage));

    std::cout << "\n--- Blur Filter Applied (Chain) ---" << std::endl;
    std::cout << "Color Mode: " << blurredGrayImage->GetColorMode() << std::endl;
    std::cout << "Final Cost: " << blurredGrayImage->Process() << " (780.0 + 5.0 + 8.0)" << std::endl;
    std::cout << "Intensity: " << blurredGrayImage->GetIntensityValue() << " (100.0 - 10.0 - 5.0)" << std::endl;

    return 0;
    // When main exits, blurredGrayImage destructor is called, which recursively deletes 
    // grayImage, which recursively deletes the original rawImage, preventing memory leaks.
}