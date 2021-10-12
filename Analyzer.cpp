#include <iostream>
#include "StringData.h"

int linearSearch(std::vector<std::string> dataSet, std::string element) {

    for(int i = 0; i < dataSet.size(); i++) {
        if(element.compare(dataSet[i]) == 0) {
            return i;
        }
    }

    return -1;
}

int binarySearch(std::vector<std::string> dataSet, std::string element) {
    int max = dataSet.size() - 1;
    int min = 0;
    int mid = min + (max- min) / 2;

    while(min <= max) {
        if(element.compare(dataSet[mid]) == 0) {
            return mid;
        } else if(element.compare(dataSet[mid]) < 0) {
            max = mid - 1;
            mid = min + (max - min) / 2;
        } else {
            min = mid + 1;
            mid = min + (max - min) / 2;
        }
    }

    return -1;
}


int main() {

    long long startTime = 0;
    long long endTime = 0;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of not_here found by linear search: " << linearSearch( getStringData(), "not_here") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Linear search time " << endTime - startTime << std::endl;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of not_here found by binary search: " << binarySearch(getStringData(), "not_here") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Binary search time " << endTime - startTime << std::endl;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of aaaaa found by linear search: " << linearSearch( getStringData(), "aaaaa") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Linear search time " << endTime - startTime << std::endl;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of aaaaa found by binary search: " << binarySearch(getStringData(), "aaaaa") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Binary search time " << endTime - startTime << std::endl;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of mzzzz found by linear search: " << linearSearch( getStringData(), "mzzzz") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Linear search time " << endTime - startTime << std::endl;

    startTime = systemTimeNanoseconds();
    std::cout << "Index of mzzzz found by binary search: " << binarySearch(getStringData(), "mzzzz") << std::endl;
    endTime = systemTimeNanoseconds();
    std::cout << "Binary search time " << endTime - startTime << std::endl;

    return 0;
}
