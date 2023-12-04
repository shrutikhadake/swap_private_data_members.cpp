//Inheritance
#include <iostream>

class A {
private:
  int x;

public:
  A(int x) : x(x) {}

  void swap(A& other) {
    std::swap(x, other.x);
  }

  void print() {
    std::cout << "x: " << x << std::endl;
  }
};

class B : public A {
private:
  int y;

public:
  B(int x, int y) : A(x), y(y) {}

  void swap(B& other) {
    A::swap(other); // Swaps the `A` portion of `this`.
    std::swap(y, other.y); // Swaps the `B` portion of `this`.
  }

  void print() {
    A::print();
    std::cout << "y: " << y << std::endl;
  }
};

int main() {
  A a(10);
  B b(20, 30);

  std::cout << "Before swapping:" << std::endl;
  a.print();
  b.print();

  a.swap(b);

  std::cout << "After swapping:" << std::endl;
  a.print();
  b.print();

  return 0;
}

