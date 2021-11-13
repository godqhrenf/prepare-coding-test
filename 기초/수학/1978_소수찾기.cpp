#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int input_num, N, prime=0;
    cin >> input_num;

    while(cin >> N) {
        int i;
        for(i=2; i<=sqrt(N) && !(N%i==0); ++i) ;
        if(!(i<=sqrt(N)) && N!=1) {
            prime++;
        }
    }

    cout << prime << endl;
    return 0;
}