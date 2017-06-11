#include <iostream>

template <typename Window, typename Controller>
class Widget {
public:
    void print() {std::cout << "General Print" << std::endl;}
};

class FooWindow;
class FooController;

template <>
class Widget<FooWindow, FooController>
{
public:
    void print() {std::cout << "Foo print" << std::endl;}
}

class BarWindow;
template <typename Controller>
class Widget<BarWindow, Controller>
{
public:
    void print() {std::cout << "Bar print" << std::endl;}
} 

int main(int argc, char **argv)
{
    return 0;
}