#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <chrono>
using namespace std::chrono;
using namespace std;

/*
Idea for part 1
    - put LHS numbers into list1
    - put RHS numbers into list2
    - sort list1 and list2
    - go through the list a keep a count of the abs(list1[i] - list2[i])
*/

/*
Idea for part 2
    - similiar to part 1, but instead of storing the values in a vector use a 
      hashmap instead (similiar to python dicts)
    - go threw lhsList and multiple the lhsList[i] * rhsMap.at(lhsList[i]) and 
      ad to the running sum

to compile
    - g++ filename.gcc
    - ./a.out
*/


ifstream parseTextFile(string textFileName) {
    ifstream textFile(textFileName);
    return textFile;
}

int main() {
    auto start = high_resolution_clock::now();
    // auto advent_of_code_input = parseTextFile("aoc_day1.txt");

    auto advent_of_code_input = parseTextFile("testing1.txt");
    if (!advent_of_code_input) {
        cerr << "Error: The file could not be openned";
        return 1;
    }

    vector<int> lhsList;
    map<int, int> rhsMap;
    string line;

    while (getline(advent_of_code_input, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            lhsList.push_back(num1);
            // rhsList.push_back(num2);
            rhsMap[num2]++;
        }
    }
    int runningSum = 0;
    for (size_t i = 0; i < lhsList.size(); i++) {
        for (const auto &pair : rhsMap) {
            if (lhsList[i] == pair.first) {
                runningSum += (lhsList[i] * pair.second);
                break;
            }
        }
    }

    cout << "The runningSum is " << runningSum << endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Total Running time is " << duration.count() << " nanoseconds " << endl;

    return 0;
}