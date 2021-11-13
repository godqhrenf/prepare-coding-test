#include <stdio.h>

int prime[1000001];

int main(void) {
    int M, N;
    scanf("%d%d", &M, &N);

    prime[1] = 1;
    for(int i=2; i*i<=N; ++i) {
        if(!prime[i]) {
            for(int j=i*i; j<=N; j+=i)
                prime[j] = 1;
        }
    }

    for(int i=M; i<=N; ++i)
        if(!prime[i])
            printf("%d\n", i);

    return 0;
}