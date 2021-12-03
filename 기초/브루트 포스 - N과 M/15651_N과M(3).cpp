#include <iostream>

using namespace std;

int N, M;
int nums[7]; // 수열

void dfs(int depth) {
    if(depth == M) {
        for(int i=0; i<M; ++i)
            cout << nums[i] << ' ';
        cout << '\n';

        return ;
    }
    else {
        for(int i=1; i<=N; ++i) {
            nums[depth] = i;
            dfs(depth+1);
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    dfs(0);   

    return 0;
}