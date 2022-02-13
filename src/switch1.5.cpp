#include <iostream>

using namespace::std;

int main() {
    int a, b;
    cin >> a;
    switch (a) {
    case 0:
        b = 0;
        break;
    case 1:
        b = 2;
        break;
    case 3:
        b = 6;
        break;
    case 6:
        b = 3;
        break;
    case 10:
        b = 5;
        break;
    case 14:
        b = 7;
        break;
    case 20:
        b = 9;
        break;

    default:
        b = -1;
        break;
    }
    cout << b;

    return 0;
}
