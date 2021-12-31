#include <iostream>

using namespace std;

int N;
int T[15], P[15];
int max_pay = 0;

void dfs(int depth, int pay) {
    if(pay > max_pay)
        max_pay = pay;
    for(int i=depth; i<N; ++i) {
        if(i + T[i] <= N) {
            dfs(i+T[i], pay+P[i]);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> T[i];
        cin >> P[i];
    }

    dfs(0, 0);

    cout << max_pay << '\n';

    return 0;
}