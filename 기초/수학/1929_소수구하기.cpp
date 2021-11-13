// 시간초과로 fail...
#include <iostream>

using namespace std;

int prime[1000001];

int main(void) {
    int M, N;
    cin >> M >> N;

    prime[1] = 1;
    for(int i=2; i*i<=N; ++i) {
        if(!prime[i]) {
            for(int j=i*i; j<=N; j+=i)
                prime[j] = 1;
        }
    }

    for(int i=M; i<=N; ++i)
        if(!prime[i])
            cout << i << endl;
    return 0;
}