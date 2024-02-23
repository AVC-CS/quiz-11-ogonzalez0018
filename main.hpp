#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

const char DELIMITER = ',';
const std::string OUTPUT_FILE = "split.txt";

int rewritesplitwords(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);
    std::string line;
    int cnt = 0;

    if (inputFile.is_open() && outputFile.is_open()) {
        while (getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string word;
            while (getline(ss, word, DELIMITER)) {
                outputFile << word << std::endl;
            }
            cnt++;
        }
        inputFile.close();
        outputFile.close();
    } else {
        std::cerr << "Unable to open file: " << (inputFile.is_open() ? outputFilename : inputFilename) << std::endl;
        return -1;
    }

    return cnt;
}

string MFN(string state, int thisyear) {
    ifstream file("split.txt");
    unordered_map<string, int> namesCount;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            string name, st;
            int year;
            stringstream ss(line);
            getline(ss, name, ',');  
            getline(ss, st, ',');    
            ss >> year;              

            if (st == state && year == thisyear) {
                namesCount[name]++;
            }
        }
        file.close();

        string mostFrequentName;
        int maxCount = 0;
        for (const auto &pair : namesCount) {
            if (pair.second > maxCount) {
                mostFrequentName = pair.first;
                maxCount = pair.second;
            }
        }
        return mostFrequentName;
    } else {
        cout << "Unable to open file: split.txt" << endl;
        return "Error"; 
    }
}

int myMain() {
    const std::string filename = "data.txt";

    int wordsWritten = rewritesplitwords(filename, OUTPUT_FILE);
    std::cout << "Total words written: " << wordsWritten << std::endl;

    std::string MFName = MFN("DE", 2018);
    std::cout << "The Most frequently used name in DE, 2018: " << MFName << std::endl;

    return 0;
}
