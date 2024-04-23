#include <iostream>
#include <string>

using namespace std;

int main() {
    system("chcp 1251 > NULL");
    string input, word, mostCommon;
    int maxCount = 0, count;

    getline(cin, input);

    input += " ";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            if (!word.empty()) {
                count = 1;
                for (int j = i + 1; j < input.size(); j++) {
                    if (input.substr(j, word.size()) == word) {
                        count++;
                    }
                }
                if (count > maxCount) {
                    maxCount = count;
                    mostCommon = word;
                }
                word = "";
            }
        }
        else {
            word += input[i];
        }
    }

    cout << mostCommon;

    return 0;
}
