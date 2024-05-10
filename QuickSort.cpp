#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& vect, int beginIndex, int pivotIndex) {
    if (beginIndex < pivotIndex) {
        int currentIndex = beginIndex;
        for (int i = currentIndex; i < pivotIndex; i++) {
            if (vect[i] < vect[pivotIndex]) {
                swap(vect[i], vect[currentIndex++]);
            }
        }
        swap(vect[currentIndex], vect[pivotIndex]);
        QuickSort(vect, beginIndex, currentIndex - 1);
        QuickSort(vect, currentIndex + 1, pivotIndex);
    }
}

void QuickSort(vector<int>& vect) {
    if (vect.size() > 1) {
        QuickSort(vect, 0, vect.size() - 1);
    }
}

int main() {
    vector<int> Values = { 38, 86, 64, 33, 56, 17, 91, 84, 31, 49 };
    for (int i = 0; i < 10; i++) {
        cout << Values[i] << "  ";
    }
    cout << endl;
    QuickSort(Values);
    for (int i = 0; i < 10; i++) {
        cout << Values[i] << "  ";
    }
    cout << endl;
    return 0;
}