#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input, '.');

    string mostFrequentWord;
    int maxCount = 0;

    string currentWord = "";
    int currentCount = 0;

    for (char c : input) {
        if (c == ' ') {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mostFrequentWord = currentWord;
            }
            currentWord = "";
            currentCount = 0;
        } else {
            currentWord += c;
            currentCount++;
        }
    }

    cout << "Most frequently occurring word: " << mostFrequentWord << endl;

    return 0;
}
