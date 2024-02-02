#include <iostream>
#include <stdlib.h>
using namespace std;
const int n = 10;
int main () {
    setlocale (LC_ALL, "RUS");
    int s,j,min;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        a[i] = rand () % 100 - 50;
    }
    min = a[0];
    s = 1;
    for(int i = 1; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
            j = i + 1;
            s = 1;
        }
        else {
            if (min == a[i]) {
                s++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    cout << "минимальное значение = " << min << endl;
    cout << "кол-во миниманых значений = " << s << endl;
    cout << "№ минимального значения = " << j << endl;
return 0;
}
