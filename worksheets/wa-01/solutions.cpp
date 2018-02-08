#include <iostream>

// Signatures
int length(const char *str);
bool is_palindrome(const char *str);
char most_frequent(const char *str);
int num_words(const char *str);
int missing_num(const int *arr, const int n);
double average_min_max(const int *arr, const int n);
void setify(const int *arr, const int n);

// Testing with main
int main()
{
    // Test Case 1
    char str[] = "ABCBAB B @";
    std::cout << "Length is: " << length(str) << std::endl;
    std::cout << "Is palindrome: " << is_palindrome(str) << std::endl;
    std::cout << "Most frequent char: " << most_frequent(str) << std::endl;
    std::cout << "Number of words: " << num_words(str) << std::endl;

    // Test Case 2
    int arr[] = {1, 2, 3, 4, 6}; // N is 6
    std::cout << "Missing number: " << missing_num(arr, 5) << std::endl;
    std::cout << "Max / min == " << average_min_max(arr, 5) << std::endl;

    std::cout << "Size of char: " << sizeof(char) << ", and int: " << sizeof(int) << std::endl;
    return 0;
}

/** Determine the length of a given string */
int length(const char *str)
{
    // So long as string[i] is not null, continue.
    int i = 0;
    while (str[i] != 0) // Could be written while (str[i]) since everything evaluates to true except 0.
        i++;
    return i;
}

/** Is a given string a palindrome? */
bool is_palindrome(const char *str)
{
    int i = 0;
    int j = length(str) - 1;
    while (i < j)
    { // If they are the same, we already know it's a palindrome.
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

/** What is the most frequent character in a given string */
char most_frequent(const char *str)
{
    // Counter array
    int arr[256] = {0};

    // Required variables
    int max_freq = 0;
    char ret = 0;

    // Main loop
    for (int i = 0; str[i] != 0; i++)
    {
        int x = (int)str[i]; // x == the character at position i
        arr[x]++;            // Increment the counter

        // Ensure we are still returning the most frequent char.
        if (arr[x] > max_freq)
        {
            max_freq = arr[x];
            ret = x;
        }
    }
    return ret;
}

/** How many words can you parse? */
int num_words(const char *str)
{
    int counter = 0;
    for (int i = 0; str[i]; i++)
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++; // Advance to next non-whitespace
        if (str[i] > 0)
            counter++; // Increment if not null
        while (str[i] >= 33 && str[i] <= 255)
            i++; // Advance to next whitespace
    }
    return counter;
}

/** What's the missing number in an array of integers 1 to n, provided length */
int missing_num(const int *arr, const int len)
{
    // This is equivilent to: sum(1, n) - sum(array).
    // A variable for the sum of the array itself:
    int sum = 0;
    // We compute the ideal sum(1, n) via:
    int target_sum = (len + 1) * (len + 2) / 2;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return target_sum - sum;
}

/** Find the average of the minimum and maximum integer within a given array */
double average_min_max(const int *arr, const int n)
{
    // Set min and max to element 0, preventing a abitrary integer living through the loop.
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        // Replace min and max whenever a smaller or larger value is found.
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    // Return the average of the two.
    return (max + (double)min) / 2;
}

/** Print a list of unique digits (0-9) in a given array */
void setify(const int *arr, const int n)
{
    int freq[10] = {0}; // Frequency array.
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++; // Incrememnt each index by one, where index == digit in the array.
    }
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            std::cout << i << " "; // For each entry with > 0 frequency, print it.
        }
    }
    std::cout << std::endl;
    return;
}