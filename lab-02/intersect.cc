#include <iostream>

char* intersect(char list1[], char list2[], char result[]) {

    /* Student code starts here */

    return result;

}

int main() {

    char a[11] = "abcdefghij";
    char b[8] = "thebird";
    char c[8] = "theword";
    char r[21];

    std::cout << intersect(a,b,r) << std::endl;
    std::cout << intersect(a,c,r) << std::endl;
    std::cout << intersect(b,c,r) << std::endl;

    return 0;

}
