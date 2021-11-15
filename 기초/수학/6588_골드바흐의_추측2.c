#include <stdio.h>

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
    eratosthenes();

    int N;
    scanf("%d", &N);

    while(N!=0) {
        int i;
        for(i=3; i<=N/2 && !(!prime[i] && !prime[N-i]); i+=2) ;

        if(i<=N/2)
            printf("%d = %d + %d\n", N, i, N-i);
        else
            printf("Goldbach's conjecture is wrong.\n");

        scanf("%d", &N);
    }
    return 0;
}