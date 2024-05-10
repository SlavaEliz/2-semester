#include <iostream>
#include <vector>
using namespace std;

void CountingSort(vector<int>& vect) {
	if (vect.size() < 2) {
		return;
	}

	int mn = vect[0];
	int mx = vect[0];
	for (int i = 1; i < vect.size(); i++) {
		if (mx < vect[i]) {
			mx = vect[i];
		}
		else if (mn > vect[i]) {
			mn = vect[i];
		}
	}

	int countingArrLenght = mx - mn + 1;
	int* countingArr = new int[countingArrLenght] {};
	for (int i = 0; i < vect.size(); i++) {
		countingArr[vect[i] - mn]++;
	}

	int index = 0;
	for (int i = 0; i < countingArrLenght; i++) {
		for (int j = 0; j < countingArr[i]; j++) {
			vect[index++] = i + mn;
		}
	}

	delete[] countingArr;
}

int main() {
	vector<int> Values = { 38, 86, 64, 33, 56, 17, 91, 84, 31, 49 };
	for (int i = 0; i < 10; i++) {
		cout << Values[i] << "  ";
	}
	cout << endl;
	CountingSort(Values);
	for (int i = 0; i < 10; i++) {
		cout << Values[i] << "  ";
	}
	cout << endl;
	return 0;
}