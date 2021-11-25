#include <iostream>

using namespace std;

#define MAX 999999

int trouble[10]; // 1이면 고장난 버튼

bool canPressButton(int number) {
    if(number < 0) // number가 0보다 작으면 누를 수 없음
        return false;
    
    if(number==0 && trouble[0]==1) // number가 0인데 0이 고장난 버튼이면 누를 수 없음
        return false;

    while(number != 0) {
        if(trouble[number%10] == 1)
            return false;
        number /= 10;
    }

    return true;
}

int numberOfDigit(int number) {
    int digit = 0;

    if(number == 0) // 이 문제에서는 0도 누를 수 있으므로 digit을 1로 해주어야 함
        digit++;

    while(number != 0) {
        digit++;
        number /= 10;
    }
    
    return digit;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int x;
    while(cin >> x) {
        trouble[x] = 1;
    }

    int min = MAX;

    // 숫자 버튼만 누른 경우
    if(canPressButton(N))
        min = min < numberOfDigit(N) ? min : numberOfDigit(N);

    // +, - 버튼만 누른 경우
    min = min < abs(N-100) ? min : abs(N-100);

    // 숫자, +, - 버튼을 누르는 경우
    int big=N, small=N;
    bool findBig=false, findSmall=false;
    for(int i=0; i<min && !findBig && !findSmall; ++i) {
        big++; small--;

        if(canPressButton(big)) {
            findBig = true;
            min = min < big-N+numberOfDigit(big) ? min : big-N+numberOfDigit(big);
        }
        if(canPressButton(small)) {
            findSmall = true;
            min = min < N-small+numberOfDigit(small) ? min : N-small+numberOfDigit(small);
        }
    }
    
    cout << min << '\n';

    return 0;
}