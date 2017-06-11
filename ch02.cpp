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

template <typename T>
class Type2Type {
using type = T;
};

class Widget {
public:
    template <typename T> Widget(const T&) {}
};

template <typename T, typename U>
T *Create(const U&arg, Type2Type<T>)
{
    return new T(arg);
}

template <typename U>
Widget *Create(const U&arg, Type2Type<Widget>)
{
    std::cout << "Wdiget Create" << std::endl;;
    return NULL;
}

int main(int argc, char **argv)
{
    auto iWidget = Create(1, Type2Type<Widget>());
    auto iInt = Create(1, Type2Type<int>());
    return 0;
}
