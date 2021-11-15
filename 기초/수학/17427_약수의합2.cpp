#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    long long gy = 0;
    for(int i=1; i<=N; ++i) {
        gy += i*(N/i);
    }

    cout << gy << endl;
    
    return 0;
}
