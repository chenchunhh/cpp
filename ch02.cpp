#include <iostream>
#include <string>

template <int v>
class Int2Type {
public:
    static constexpr int value = v;
};

template <typename T, bool isInt>
class CompileTimeDispatch {
public:
    void doSomething() {
        doSomething(Int2Type<isInt>());
    }
private:
    void doSomething(Int2Type<true> value) {std::cout << "True" << std::endl;}
    void doSomething(Int2Type<false> value) {std::cout << "False" << std::endl;}
};

class Widget {
public:
    template <typename T> Widget(const T&) {}
};

template <typename T, typename U>
T *Create(const U&arg, const T&)
{
    return new T(arg);
}

int main(int argc, char **argv)
{
    auto iWidget = Create<Widget>(1, Widget(1));
    auto strWidget = Create<Widget>(std::string(), Widget(1));
    return 0;
}
