#include <iostream>

using namespace std;

int main(void) {
    int num;

    while(cin >> num) {
        int multiple=1, digit=1;
        while(multiple % num != 0) {
            multiple = multiple * 10 + 1;
            multiple %= num;
            digit++;
        }
        cout << digit << endl;
    }

    return 0;
}