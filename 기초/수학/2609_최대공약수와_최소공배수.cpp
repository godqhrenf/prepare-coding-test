#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}

int main(void) {
    int a, b;
    cin >> a >> b;

    int g = a>b ? gcd(a, b) : gcd(b, a);
    int l = a * b / g;

    cout << g << endl;
    cout << l << endl;

}