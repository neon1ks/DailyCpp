#include <iostream>

#include <functional>

using namespace std;

void rebind(std::function<void()> &f,
            const std::function<void(const std::function<void()> &handler)> &new_one)
{
    std::function<void()> origin;
    std::swap(origin, f);
    f = [new_one, origin]() { new_one(origin ? origin : []() {}); };
}

int main()
{
    cout << "==============================" << std::endl;

    std::function<void()> myFunc = []() { std::cout << "origin myFunc()" << std::endl; };
    myFunc();

    cout << "==============================" << std::endl;

    const int number = 55;
    rebind(myFunc, [number](const std::function<void()> &handler) {
        cout << "Start" << endl;
        cout << "Number = " << number << endl;
        handler();
        cout << "Finish" << endl;
    });
    myFunc();

    cout << "==============================" << std::endl;

    rebind(myFunc, [](const std::function<void()> &handler) {
        cout << "Wrap begin" << endl;
        handler();
        cout << "Wrap end" << endl;
    });
    myFunc();

    cout << "==============================" << std::endl;

    return 0;
}
