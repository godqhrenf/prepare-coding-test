#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
int maximum = -999999;
int board[10][10];
vector< tuple<int, int, int> > nums; // num, r, c

bool is_adjacent(int r, int c, int len) {
    for(int i=0; i<len; ++i) {
        if((get<1>(nums[i])==r && abs(get<2>(nums[i])-c)==1) || (get<2>(nums[i])==c && abs(get<1>(nums[i])-r)==1)) {
            return true;
        }
    }

    return false;
}

void dfs(int depth) {
    if(depth == K) {
        int temp = 0;
        for(int i=0; i<nums.size(); ++i)
            temp += get<0>(nums[i]);
        
        maximum = maximum > temp ? maximum : temp;

        return ;
    }
    else {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if((depth == 0) || (i > get<1>(nums[depth-1])) || (i == get<1>(nums[depth-1]) && j > get<2>(nums[depth-1]))) {
                    if(!is_adjacent(i, j, depth)) {
                        nums[depth] = make_tuple(board[i][j], i, j);
                        dfs(depth+1);
                    }
                }
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> K;
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    nums.resize(K);

    dfs(0);

    cout << maximum << '\n';

    return 0;
}