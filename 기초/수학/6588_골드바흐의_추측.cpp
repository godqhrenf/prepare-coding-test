#include <iostream>
#include <string>

using namespace std;

#define N_MAX 1000000
int prime[N_MAX+1];

void eratosthenes(void) { // 0: prime, 1: not prime
    prime[0] = prime[1] = 1;
    for(int i=2; i*i<=N_MAX; ++i) {
        if(!prime[i])
            for(int j=i*i; j<=N_MAX; j+=i)
                prime[j] = 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    eratosthenes();

    int N;
    string s;
    while((cin >> N) && N!=0) {
        int i;
        for(i=3; i<=N/2 && !(!prime[i] && !prime[N-i]); i+=2) ;

        if(i<=N/2) {
            s = to_string(N);
            s += " = ";
            s += to_string(i);
            s += " + ";
            s += to_string(N-i);           
            s += "\n";
            cout << s;
        }
        else
            cout << "Goldbach's conjecture is wrong.";
    }
    return 0;
}