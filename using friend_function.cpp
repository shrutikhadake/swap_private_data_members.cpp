//Friend Function
#include <iostream>

class Data {
private:
    int value;

public:
    Data(int value) : value(value) {}

    friend void swap(Data& a, Data& b) {
        int temp = a.value;
        a.value = b.value;
        b.value = temp;
    }

    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Data a(10);
    Data b(20);

    std::cout << "Before swapping:" << std::endl;
    a.print();
    b.print();

    swap(a, b);

    std::cout << "After swapping:" << std::endl;
    a.print();
    b.print();

    return 0;
}
