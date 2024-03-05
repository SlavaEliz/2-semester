#include <iostream>
#include <string>

using namespace std;

void clearMemory(string* arr, int size) {
    for (int i = 0; i < size; i++) {
        delete[] &arr[i];
    }
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    string* arr = new string[size];
    cout << "Введите элемент массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int shortestIndex = 0;
    int shortestLength = arr[0].length();
    for (int i = 1; i < size; i++) {
        if (arr[i].length() < shortestLength) {
            shortestIndex = i;
            shortestLength = arr[i].length();
        }
    }

    cout << "Наименьший элемент: " << arr[shortestIndex] << endl;

    for (int i = shortestIndex; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    
    string new_arr[size];
    
    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
        cout << new_arr[i] << " ";
    }
    cout << endl;
    clearMemory(arr, size);

    return 0;
}
