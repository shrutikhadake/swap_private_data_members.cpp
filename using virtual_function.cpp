//Virtual Function
#include <iostream>

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    virtual void swapValues(Data& other) = 0;

    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
};

class DataImpl : public Data {
public:
    DataImpl(int value) : Data(value) {}

    void swapValues(Data& other) override {
        int temp = value;
        value = other.value;
        other.value = temp;
    }
};

class DataDerived : public Data {
public:
    DataDerived(int value) : Data(value) {}

    void swapValues(Data& other) override {
        // Implement custom swapping logic for derived data
        std::cout << "Swapping values in DataDerived" << std::endl;
        int temp = value;
        value = other.value;
        other.value = temp;
    }
};

int main() {
    DataImpl a(10);
    DataDerived b(20);

    std::cout << "Before swapping:" << std::endl;
    a.print();
    b.print();

    Data& d1 = a; // Use base class reference for swapping
    Data& d2 = b; // Use base class reference for swapping

    d1.swapValues(d2);

    std::cout << "After swapping:" << std::endl;
    a.print();
    b.print();

    return 0;
}
