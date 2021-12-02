#include <iostream>

using namespace std;

int N, M;
bool visited[9]; // 방문한 노드 체크
int nums[8]; // 수열

void dfs(int depth) {
    if(depth == M) {
        for(int i=0; i<M; ++i)
            cout << nums[i] << ' ';
        cout << '\n';

        return ;
    }
    else {
        for(int i=1; i<=N; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                nums[depth] = i;
                dfs(depth+1);

                // 방문하고 돌아오면 다시 false로 해줘야 함
                visited[i] = false;
            }
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