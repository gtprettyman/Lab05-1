#include "StringData.h"
#include <iostream>
#include <string>

    long linearSearch(std::vector<std::string> direct, std::string element) {
        for (int index = 0; index < direct.size(); index++) {
            if (direct[index] == element) {
                return index;
            }
        }
        return -1;
    }

    long binarySearch(std::vector<std::string> direct, std::string element) {
        int min = 0;
        int max = direct.size()-1;
        while (min <= max) {
            int middle = (min + max) / 2;
            int difference = element.compare(direct[middle]);
            if (difference < 0) {
                max = middle - 1;
            } else if (difference > 0) {
                min = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }

    int main() {
        std::vector<std::string> direct = getStringData();

        int index;

        auto time1 = systemTimeNanoseconds();
        index = linearSearch(direct, "not here");
        auto time2 = systemTimeNanoseconds();
        auto difference = time2 - time1;
        std::cout << "Linear search found not here at " << index << " in " << difference<< std::endl;
        time1=systemTimeNanoseconds();
        index= binarySearch(direct, "not here");
        time2 = systemTimeNanoseconds();
        difference = time2-time1;
        std::cout <<"Binary search found not here at " << index << " in " << difference << std::endl;
        time1 = systemTimeNanoseconds();
        index = linearSearch(direct, "mzzzz");
        time2 = systemTimeNanoseconds();
        difference = time2 - time1;
        std::cout << "Linear search found mzzzz at " << index << " in " << difference << std::endl;
        time1 = systemTimeNanoseconds();
        index = binarySearch(direct, "mzzzz");
        time2 = systemTimeNanoseconds();
        difference = time2 - time1;
        std::cout << "Binary search found mzzzz at " << index << " in " << difference << std::endl;
        time1 = systemTimeNanoseconds();
        index = linearSearch(direct, "aaaaa");
        time2 = systemTimeNanoseconds();
        difference = time2 - time1;
        std::cout << "Linear search found aaaaa at " << index << " in " << difference << std::endl;
        time1 = systemTimeNanoseconds();
        index = binarySearch(direct, "aaaaa");
        time2 = systemTimeNanoseconds();
        difference = time2 - time1;
        std::cout << "Binary search found aaaaa at " << index << " in " << difference << std::endl;
        return 0;
    }


