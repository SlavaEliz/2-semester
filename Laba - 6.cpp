#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

std::string findMostFrequentWord(const std::string& str) {
    std::unordered_map<std::string, int> wordFreq;
    std::istringstream iss(str);
    std::string word;
    
    while (iss >> word) {
        wordFreq[word]++;
    }

    std::string mostFrequentWord;
    int maxFreq = 0;

    for (const auto& pair : wordFreq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    return mostFrequentWord;
}

int main() {
    std::string text = "no info in this text, no mind on a head";
    std::string mostFrequent = findMostFrequentWord(text);
    
    std::cout << "The most frequent word is: " << mostFrequent << std::endl;

    return 0;
}
