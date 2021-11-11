#include <iostream>

using namespace std;

int main(void) {
    int divisor_num;
    cin >> divisor_num;

    int min = 123456789;
    int max = 0;
    int divisor;
    while(cin >> divisor) {
        min = divisor < min ? divisor : min;
        max = divisor > max ? divisor : max;
    }

    cout << min*max << endl;
    
    return 0;
}