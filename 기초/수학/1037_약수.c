#include <stdio.h>

int main(void) {
    int divisor_num;
    scanf("%d", &divisor_num);

    int min = 123456789;
    int max = 0;
    int divisor;
    for(int i=0; i<divisor_num; i++) {
        scanf("%d", &divisor);
        min = divisor < min ? divisor : min;
        max = divisor > max ? divisor : max;
    }

    printf("%d", min*max);
    return 0;
}