#include <generator>
#include <iostream>
#include <utility>

// The return type has to conform to coroutine requirements
std::generator<int> fibonacci(int cnt) {
    int a = 0;
    co_yield a;
    int b = 1;
    co_yield b;
    for (; cnt > 0; --cnt) {
        int next = a + b;
        a = b;
        b = next;
        co_yield next;
    }

}

int main() {
    for (int v: fibonacci(10)) {
        std::cout << v << " ";
    }
}