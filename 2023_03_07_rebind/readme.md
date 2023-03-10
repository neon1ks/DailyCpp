# rebind

Создание обёртки над функцией:

```cpp
void rebind(std::function<void()> &f,
            const std::function<void(const std::function<void()> &handler)> &new_one)
{
    std::function<void()> origin;
    std::swap(origin, f);
    f = [new_one, origin]() { new_one(origin ? origin : []() {}); };
}
```

Принимает оригинальную функцию и функцию обертки, в которой через `handler` вызывается оригинальная функция.

Пример:

```cpp
std::function<void()> myFunc = []() { std::cout << "origin myFunc()" << std::endl; };
rebind(myFunc, [](const std::function<void()> &handler) {
    cout << "Before" << endl;
    handler();
    cout << "After" << endl;
});
myFunc();
```

Вывод:

```text
Before
origin myFunc()
After
```