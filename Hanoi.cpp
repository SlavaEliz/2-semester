#include <iostream>
using namespace std;

static int i = 1;

int han(int n, int start, int temp, int point) {
if (n > 0) {
han (n - 1, start, point, temp);
cout << start << " => " << temp << "  " << i++ << endl;
han (n - 1, point, temp, start);
}
return 0;
}
int main () {

int n;
cout << "";
cin >> n;
han(n, 1, 3, 2);
return 0;
}
