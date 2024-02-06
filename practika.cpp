#include <iostream>
using namespace std;

int n = 7;

int main () {
    int a[n][n];
    int r = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = r; j < (n-r); j++) {
            a[i][j] = 0;
        }
        r++;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }

return 0;
}
