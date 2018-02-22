#include <iostream>

void f2(int n);

void f1(int n) {
    if (n > 1) {
        std::cout << "h";
        f2(n - 1);
    }
}

void f2(int n) {
    std::cout << "a";
    f1(n - 1);
}

void reverse(char *str, int len) {
    if (len > 1) {
        // swap characters
        char temp = str[len-1];
        str[len-1] = str[0];
        str[0] = temp;
        // recursive call
        reverse(str+1, len-2);
    }
}

void print_binary(int n) {
    if (n > 0) {
        print_binary(n/2);
        std::cout << n % 2;
    }
}

int foo(int n) {
    int a = 10;
    n += a;
    return n;
}

int bar(int n) {
    int a = 10;
    n = foo(n);
    return a * n;
}

int sum_array(int *A, int n) {
    // base case
    if (n == 1) {
        return A[0];
    }
    // recursive call
    return A[n-1] + sum_array(A, n-1);
}

int power(int x, int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    // recursive call
    return x * power(x, n-1);
}


int factorial(int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    // recursive call
    return n * factorial(n-1);
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << factorial(5) << std::endl;
    std::cout << power(2, 8) << std::endl;
    std::cout << sum_array(array, 5) << std::endl;
    std::cout << bar(5) << std::endl;
    print_binary(27);
    std::cout << std::endl;
    f1(9);
    std::cout << std::endl;
    char word[] = "hello";
    reverse(word, 5);
    std::cout << word << std::endl;
}
