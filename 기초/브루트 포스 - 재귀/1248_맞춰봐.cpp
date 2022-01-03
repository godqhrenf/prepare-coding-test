#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector< vector<char> > S;
vector<int> A;

bool is_correct(int length) {
    for(int i=0; i<length; ++i) {
        int sum = 0;
        for(int j=i; j<length; ++j) {
            sum += A[j];

            if(S[i][j] == '-' && !(sum < 0)) return false;
            else if(S[i][j] == '+' && !(sum > 0)) return false;
            else if(S[i][j] == '0' && !(sum == 0)) return false;
        }
    }

    return true;
}

void dfs(int depth) {    
    if(depth == N) {
        for_each(A.begin(), A.end(), [](auto _a) { cout << _a << ' '; });
        cout << '\n';

        exit(0);
    }

    for(int i=-10; i<=10; ++i) {
        A[depth] = i;
        if(is_correct(depth+1))
            dfs(depth+1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    S.resize(N, vector<char>(N, ' '));
    A.resize(N);

    for(int i=0; i<N; ++i)
        for(int j=i; j<N; ++j)
            cin >> S[i][j];

    dfs(0);

    return 0;
}