#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N, min_diff=987654321;
vector< vector<int> > S;
vector<int> team_total, team_start, team_link;

void dfs(int depth, int cnt) {
    if(depth == cnt) {
        int s_start=0, s_link=0;

        set_difference(team_total.begin(), team_total.end(), team_start.begin(), team_start.end(), team_link.begin());

        for(int i=0; i<cnt; ++i)
            for(int j=0; j<cnt; ++j)
                s_start += S[team_start[i]][team_start[j]];

        for(int i=0; i<N-cnt; ++i)
            for(int j=0; j<N-cnt; ++j)
                s_link += S[team_link[i]][team_link[j]];

        if(abs(s_start - s_link) < min_diff)
            min_diff = abs(s_start - s_link);

        return ;
    }

    for(int i=0; i<N; ++i) {
        if(depth == 0 || team_start[depth-1] < i) {
            team_start[depth] = i;
            dfs(depth+1, cnt);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    S.resize(N, vector<int>(N));
    team_total.resize(N);
    iota(team_total.begin(), team_total.end(), 0);

    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> S[i][j];
    
    for(int i=1; i<=N/2; ++i) {
        team_start.resize(i);
        team_link.resize(N-i);
        dfs(0, i);
    }

    cout << min_diff << '\n';

    return 0;
}