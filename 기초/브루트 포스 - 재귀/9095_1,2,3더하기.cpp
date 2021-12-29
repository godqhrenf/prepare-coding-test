#include <iostream>

using namespace std;

int cnt;

void number_of_sum(int N) {
    if(N >= 1 && N <= 3) {
        cnt++;
    }

    if(N - 1 >= 1)
        number_of_sum(N-1);
    if(N - 2 >= 1)
        number_of_sum(N-2);
    if(N - 3 >= 1)
        number_of_sum(N-3);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T;

    while(cin >> N) {
        cnt = 0;
        number_of_sum(N);
        cout << cnt << '\n';
    }
    return 0;
}