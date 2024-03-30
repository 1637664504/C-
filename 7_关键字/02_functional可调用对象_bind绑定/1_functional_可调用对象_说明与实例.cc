# include <iostream>
# include <functional>

typedef std::function<int(int, int)> comfun;

// 普通函数
int add(int a, int b) { return a + b; }

// lambda表达式
auto mod = [](int a, int b) { return a % b; };

// 函数对象类
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main() {
    comfun a = add;
    comfun b = mod;
    comfun c = divide();
    std::cout << a(5, 3) << std::endl;
    std::cout << b(5, 3) << std::endl;
    std::cout << c(5, 3) << std::endl;
}
