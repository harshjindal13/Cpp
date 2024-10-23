#include <iostream>
using namespace std;

void add(int, int);
void add(int, float);
void add(int, int, int);

int main() {
    add(2, 3);        // Calls add(int, int)
    add(2, 3.5f);     // Calls add(int, float), note the explicit float
    add(2, 3, 4);     // Calls add(int, int, int)

    return 0;
}

void add(int a, int b) {
    cout << "\n Addition = " << a + b;
}

void add(int a, float b) {
    cout << "\n Addition = " << a + b;
}

void add(int a, int b, int c) {
    cout << "\n Addition = " << a + b + c;
}
