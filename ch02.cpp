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
class Type2TYpe {
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

template <typename T, typename U>
class Conversion {
private:
    typedef char Small;
    struct big {char data[2]};
    static Small Test(U);
    static Big Test(...);
    static T makeT();
public:
    static constexpr int value == (sizeof(Test(makeT()) == sizeof(Small)));
};

int main(int argc, char **argv)
{
    std::cout << Conversion<int, long>::value << std::endl;
    std::cout << Conversion<float, int>::value << std::endl;
    return 0;
}
