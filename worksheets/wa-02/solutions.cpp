#include <iostream>

#ifndef MY_CONSTANTS
#define ARR_LEN 5
#endif

/** 1) Draw the array represented by `int arr[5];` use null to denote uninitialized memory. */
void array_peak()
{
    int arr[ARR_LEN];
    for (size_t i = 0; i < ARR_LEN; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return;
    // Should be: arr = [null, null, null, null, null];
}

/** 2) Now redraw the array after this code executes: `*arr = 1; *(arr+2) = 5;` */
void array_peak_2()
{
    int arr[ARR_LEN];
    *arr = 1;
    *(arr + 2) = 5;
    for (size_t i = 0; i < ARR_LEN; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return;
}

/** 3) What is the output of the following code? If it breaks at any point, indicate what went wrong. */
/**
    #include <iostream>
    int mystery(int x, int* y) {
      x = x + 10;
      *y = x * 2;
      return x;
    }
    int* mystery2() {
      int x = 50;
      return &x; // This returns a bad pointer, to an object that will get erase when the call ends.
    }
    int main() {
      int x = 2, y = 3;
      x = mystery(x, &y);
      std::cout << "(x, y): (" << x << ", " << y << ")" << std::endl; // (12, 24)
      int* z = mystery2();
      std::cout << "z: " << *z << std::endl;
}
*/

/** 4) Define a void function that takes a pointer to an integer variable as a parameter, and incrememnts its value by 10. */
void plus_10(int *x)
{
    *x += 10;
    return;
}

/** 5) Define a function that sets an arbitrary value of an array. The fucntion should have the following prototype:
 * `void set_value(int* arr, const int n, const int idx, const int val);
 * It should prevent users from inserting values beyond the end of the array.
 */
void set_value(int *arr, const int n, const int idx, const int val)
{
    if (idx < n)
        arr[idx] = val;
    // else throw; could throw an error here, depending on how you want it to fail!
    else
        std::cout << "You tried to insert out of bounds, nothing changed.\n";
}

/** 6) Define a function that creates a new integer array on the heap and returns a pointer to that array.
 * The function should take the length of the array to generate as a parameter.
 */
int *gen_array(const int n)
{
    int *ret = new int[n];
    return ret;
}

/** 7) Define a second function that recieves a pointer to a previously allocated array and frees the memory. 
 * `void free_mem(int* arr);
 */
void free_mem(int *arr)
{
    delete[] arr;
    return;
}

/** Main for Testing */
int main(void)
{
    array_peak();
    array_peak_2();

    int x = 5;
    plus_10(&x);
    std::cout << x << std::endl;

    int arr[ARR_LEN] = {0};
    set_value(arr, ARR_LEN, ARR_LEN / 2, 10);
    for (size_t i = 0; i < ARR_LEN; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Trying out of bounds
    set_value(arr, ARR_LEN, ARR_LEN * 2, 10);

    int *heap_arr = gen_array(ARR_LEN);
    for (size_t i = 0; i < ARR_LEN; i++)
        std::cout << heap_arr[i] << " ";
    std::cout << std::endl;

    // This is undefined behavior, **caution**
    free_mem(heap_arr);
    for (size_t i = 0; i < ARR_LEN; i++)
        std::cout << heap_arr[i] << " ";
    std::cout << std::endl;
}

/** OPTIONAL QUESTIONS */

/** 1) Provide a detailed explanation as to what happened in question 4, 
 * can you suggest any ways to fix the issue present in the code?
 * 
 * The function returns a bad pointer, it can be fixed using the new operator
 */

/** 2) The std::vector class uses arrays internally, 
 * yet a std::vector is capable of dynamically resizing itself. 
 * Can you think of how you would write the method expand? 
 * This is a challenging question, which is why it is optional, 
 * but this type of thinking is highly valuable.
 * 
 * Creating a new array, transferring the old values to the new one, then
 * deleteing the old array. The new array should be double in size, this 
 * is considered the "best" way to grow arrays.
 */
