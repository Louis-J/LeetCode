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
    case 2:
        b = 4;
        break;
    case 30:
        b = 6;
        break;
    case 4:
        b = 8;
        break;
    case 5:
        b = 1;
        break;
    case 6:
        b = 3;
        break;
    case 7:
        b = 5;
        break;
    case 8:
        b = 7;
        break;
    case 100:
        b = 9;
        break;

    default:
        b = -1;
        break;
    }
    cout << b;

    return 0;
}
