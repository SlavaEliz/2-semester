#include <iostream>
#include <cmath>
using namespace std;

static int i = 1;
static double S = 0;

void func (double x, int n, int i) {
    double F;
    if (i <= n) {
        F = cos((((2*i) - 1) * x)/(((2*i) - 1)^2));
    }
    S += F;
    if (i == n) {
        cout << "Сумма равна " << S << endl;
        cout << i;
    }
    else {
        i++;
        func(x, n, i);
    }
} 

int main () {
    int n;
    double x;
    
    cout << "Введите Х и N" << endl;
    cin >> x >> n;
    
    if (n < 1) {
        cout << "N должно быть не меньше 1" << endl << "Введите другое N" << endl;
        cin >> n;
    }
    func (x, n, i);
    return 0;
}
