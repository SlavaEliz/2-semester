#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "no info, no mind, no brain, head empty.";
    string word;
    int maxCount = 0;
    string mostFrequentWord;

    for (int i = 0; i < text.size(); ++i) {
        if (text[i] != ' ' && text[i] != '.') {
            word += text[i];
        } else {
            int count = 0;
            for (int j = 0; j < text.size(); ++j) {
                string temp;
                while (j < text.size() && text[j] != ' ' && text[j] != '.') {
                    temp += text[j];
                    ++j;
                }
                if (temp == word) {
                    ++count;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                mostFrequentWord = word;
            }
            word = "";
        }
    }

    cout << "The most frequent word is: " << mostFrequentWord << endl;

    return 0;
}
