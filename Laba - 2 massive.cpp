#include <iostream>
#include <stdlib.h>
using namespace std;
int n = 7;
int main () {
    setlocale (LC_ALL, "RUS");
    int r,j;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        a[i] = rand () % 100 - 50;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
    
    for(int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            for(int j = i; j < n; j++) {
            r = a[j+1];
            a[j] = r;
            }
            n--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    cout << endl;
return 0;
}
