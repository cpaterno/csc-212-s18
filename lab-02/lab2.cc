#include <iostream>

void say_hello();

int add(int num1, int num2) {

    int sum = num1 + num2;
    return sum;

}

void subtract_five(int *num1) {

    *num1 -= 5;

}

int main() {

    int seven = add(3, 4);

    std::cout << "The sum of 3 and 4 is " << seven << std::endl;

    int a = 10;
    int b = 20;

    // Passing by value
    int c = add(a, b);

    // Passing by reference
    subtract_five(&a);

    return 0;
}

void say_hello() {

    std::cout << "Hello world!" << std::endl;

}
