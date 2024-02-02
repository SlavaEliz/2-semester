#include <iostream>
#include <stdlib.h>
using namespace std;
int n = 5;
int main () {
    setlocale (LC_ALL, "RUS");
    char b;
    int j = 1;
    int z = 0;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        a[i] = j;
        j++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    cout << "введите 'Y' если да" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << "-й пришел? " << endl;
        cin >> b;
        if (b == 'y') {
            cout << "          " << a[i] << "-й пришел" << endl;
            cout << a[i] << "-й ушел?" << endl;
            cin >> b;
            if (b == 'y') {
                cout << "          " << a[i] << "-й ушел" << endl;
                z = z + 1;
            }
            else {
                cout << "          " << "помянем" << endl;
            }
        }
        else {
            cout << "          " << a[i] << "-й не пришел" << endl;
        }
    }    
    cout << "всего осталось " << z << endl;
return 0;
}
