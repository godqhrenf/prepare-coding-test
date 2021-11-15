#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n) { // n>=3, odd
    int i;
    for(i=3; (i*i<=n) && !(n%i==0); i+=2) ;
    
    if(i*i<=n)
        return false;
    else
        return true;
}

int main(void) {
    int N;
    scanf("%d", &N);
    while(N!=0) {
        int i;
        for(i=3; i<=N/2 && !(is_prime(i) && is_prime(N-i)); i+=2) ;

        if(i<=N/2)
            printf("%d = %d + %d\n", N, i, N-i);
        else
            printf("Goldbach's conjecture is wrong.\n");
        
        scanf("%d", &N);
    }
    return 0;
}