#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, digit=0;
    cin >> N;

    for(int i=1; i<=N; i*=10)
        digit += N - i + 1;
    
    cout << digit << '\n';
    
    return 0;
}