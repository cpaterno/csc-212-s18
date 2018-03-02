#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <chrono>

void testMerge(int n);
void testMergeSort(int n);
void raceMergeSorts(int n);
void merge(int* A, int n, int mid);
void MergeSort(int* A, int n);

void merge(int* A, int n, int mid) {
    int* B = new int[n];
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    int x = 0;
    int y = mid;
    int idx = 0;
    while (x < mid && y < n) {
        if (B[x] < B[y]) {
            A[idx++] = B[x++];
        } else {
            A[idx++] = B[y++];
        }
    }

    if (x < mid) {
        y = x;
        n = mid;
    }

    for (int i = y; i < n; i++) {
        A[idx++] = B[i];
    }

    delete [] B;
}

void MergeSort(int* A, int n) {
    if (n != 1) {
        MergeSort(A, n/2);
        int n2 = (n % 2 == 0) ? n/2 : n/2 + 1;
        MergeSort(A + n/2, n2);
        merge(A, n, n/2);
    }
}

void customTest(int n) {

    /* You can write your own additional tests here if you would like */

}

void testMerge() {
    //Test the merge function
    std::ifstream mergeIn("mergeTest.in");
    std::ifstream mergeOut("mergeTest.out");
    std::string line;
    int cases = 1;
    while(std::getline(mergeIn, line)) {
        std::string outline;
        std::getline(mergeOut, outline);
        std::string a1 = line.substr(0,line.find(","));
        std::string a2 = line.substr(line.find(",")+1);
        //std::cout << a1 << std::endl;
        //std::cout << a2 << std::endl;
        int length1;
        std::stringstream stream1(a1);
        stream1 >> length1;
        int length2;
        std::stringstream stream2(a2);
        stream2 >> length2;

        int *array = new int[length1+length2];
        for(int i = 0; i < length1; i++) {
            stream1 >> array[i];
        }
        for(int i = 0; i < length2; i++) {
            stream2 >> array[length1+i];
        }

        int outlength = length1 + length2;
        std::stringstream outstream(outline);
        int *outarray = new int[outlength];
        for(int i = 0; i < outlength; i++) {
            outstream >> outarray[i];
        }

        merge(array, outlength, length1);

        for(int i = 0; i < outlength; i++) {
            if(array[i] != outarray[i]) {
                std::cout << "Error on test case: " << cases << std::endl;
                std::cout << "Your Array: ";
                for(int i = 0; i < length1; i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "Target Array: ";
                for(int i = 0; i < outlength; i++) {
                    std::cout << outarray[i] << " ";
                }
                std::cout << std::endl;
                return;
            }
        }
        cases++;

    }
}

void testMergeSort(int n) {
    //Test the mergeSort function
    std::ifstream sortIn("sortTest.in");
    std::ifstream sortOut("sortTest.out");
    std::string line;
    int cases = 1;
    while(std::getline(sortIn, line)) {
        std::string outline;
        std::getline(sortOut, outline);
        std::stringstream stream(line);
        int n;
        stream >> n;
        int *array = new int[n];
        for(int i = 0; i < n; i++) {
            stream >> array[i];
        }
        int *sortedarray = new int[n];
        std::stringstream stream2(outline);
        for(int i = 0; i < n; i++) {
            stream2 >> sortedarray[i];
        }

        MergeSort(array, n);

        for(int i = 0; i < n; i++) {
            if(array[i] != sortedarray[i]) {
                std::cout << "Error on test case: " << cases << std::endl;
                std::cout << "Your Array: ";
                for(int i = 0; i < n; i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "Target Array: ";
                for(int i = 0; i < n; i++) {
                    std::cout << sortedarray[i] << " ";
                }
                std::cout << std::endl;
                return;
            }
        }
        cases++;
    }

}

raceMergeSorts(int n) {

}

// Generate a random, unsorted list
int* gen_list_unsorted(unsigned int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

int main(int argc, char** argv) {

    /* Input validation */
    if (argc != 3) {
        std::cerr << "Invalid Arguments. Usage: test_type(str) input_size(int)" << std::endl;
        return 1;
    }
    char test_types[4][11] = {"merge", "merge_sort", "ms_vs_msp", "custom"};
    bool valid = false;
    for (int i = 0; i < 4; i++) {
        if (strcmp(argv[1], test_types[i])) {
            valid = true;
            break;
        }
    }
    if (!valid) {
        std::cerr << "Invalid Arguments. Possibilities for test_type are:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << test_types[i] << std::endl;
        }
        return 2;
    }
    if (atoi(argv[2]) <= 0) {
        std::cerr << "Invalid Arguments. Please enter a valid number n > 0."
        return 3;
    }


    int input_size = atoi(argv[2]);
    if (!strcmp(argv[1], test_types[0])) {

        testMerge(input_size);

    } else if (!strcmp(argv[1], test_types[1])) {

        testMergeSort(input_size);

    } else if (!strcmp(argv[1], test_types[2])) {

        raceMergeSorts(input_size);

    } else if (!strcmp(argv[1], test_types[3])) {

        customTest(input_size);

    }
    return 0;
}
