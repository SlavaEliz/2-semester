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

void BucketSort(vector<int>& vect) {
	if (vect.size() < 2) {
		return;
	}

	int mx = vect[0];
	int mn = vect[0];
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i] > mx) {
			mx = vect[i];
		}
		else if (vect[i] < mn) {
			mn = vect[i];
		}
	}

	int bucketsLenght = mx / 10 - mn / 10 + 1;
	vector<int>* buckets = new vector<int>[bucketsLenght] {};

	for (int i = 0; i < vect.size(); i++) {
		buckets[vect[i] / 10 - mn / 10].push_back(vect[i]);
	}

	for (int i = 0; i < bucketsLenght; i++) {
		QuickSort(buckets[i]);
	}

	int index = 0;
	for (int i = 0; i < bucketsLenght; i++) {
		for (int j = 0; j < buckets[i].size(); j++) {
			vect[index++] = buckets[i][j];
		}
	}

	delete[] buckets;
}

int main() {
    vector<int> Values = { 38, 86, 64, 33, 56, 17, 91, 84, 31, 49 };
    for (int i = 0; i < 10; i++) {
        cout << Values[i] << "  ";
    }
    cout << endl;
    BucketSort(Values);
    for (int i = 0; i < 10; i++) {
        cout << Values[i] << "  ";
    }
    cout << endl;
    return 0;
}