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
};

class BarWindow;
template <typename Controller>
class Widget<BarWindow, Controller>
{
public:
    void print() {std::cout << "Bar print" << std::endl;}
};

template <typename ButtonArg>
class Button;

template <typename ButtonArg, typename Controller>
class Widget<Button<ButtonArg>, Controller>
{
public:
    void print() {std::cout << "Button print" << std::endl;}
};

void Func()
{
    class Local {
    public:
        void print() {std::cout << __func__ << std::endl;};
    };

    Local local;
    local.print();
}


int main(int argc, char **argv)
{
    Widget<int, int> intWidget;
    intWidget.print();

    Widget<FooWindow, int> fooIntWidget;
    fooIntWidget.print();

    Widget<FooWindow, FooController> fooWidget;
    fooWidget.print();

    Widget<BarWindow, int> barWidget;
    barWidget.print();

    Widget<Button<int>, int> buttonWidget;
    buttonWidget.print();
    return 0;
}
