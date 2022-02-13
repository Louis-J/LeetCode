#include <iostream>

using namespace::std;

int main() {
    int a, b;
    cin >> a;
    switch (a) {
    case 0:
        b = 0;
        break;
    case 10:
        b = 2;
        break;
    case 20:
        b = 4;
        break;
    case 30:
        b = 6;
        break;
    case 40:
        b = 8;
        break;
    case 50:
        b = 1;
        break;
    case 60:
        b = 3;
        break;
    case 70:
        b = 5;
        break;
    case 80:
        b = 7;
        break;
    case 90:
        b = 9;
        break;

    default:
        b = -1;
        break;
    }
    cout << b;

    return 0;
}
