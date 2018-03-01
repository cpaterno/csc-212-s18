#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void testMergeSort();
void testMerge();
void merge(int* A, int n, int mid);
void MergeSort(int* A, int n);


int main() {

    //Uncomment the following lines to test merge and MergeSort respectively
    //testMerge();
    //testMergeSort();

}

void merge(int* A, int n, int mid) {
    /*
        Implement the merge function here
    */
}

void MergeSort(int* A, int n) {
    /*
        Implement the MergeSort function here
    */
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
        std::cout << a1 << std::endl;
        std::cout << a2 << std::endl;
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

void testMergeSort() {
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
// Generate a random, unsorted list
int* gen_list_unsorted(int size) {

    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}
