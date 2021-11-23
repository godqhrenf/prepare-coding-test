#include <iostream>
#include <vector>

using namespace std;

int find_max_candy(const int N, const vector< vector<char> >& candy) {
    int max_candy = 1;

    // 행(row)에서 사탕 최대 개수 찾기
    for(int i=0; i<N; ++i) {
        int max_temp = 1;
        for(int j=0; j<N-1; ++j) {
            if(candy[i][j] == candy[i][j+1]) {
                max_temp++;
            }
            else {
                max_candy = max_candy > max_temp ? max_candy : max_temp;
                max_temp = 1;
            }
        }
        max_candy = max_candy > max_temp ? max_candy : max_temp;
    }

    // 열(column)에서 사탕 최대 개수 찾기
    for(int i=0; i<N; ++i) {
        int max_temp = 1;
        for(int j=0; j<N-1; ++j) {
            if(candy[j][i] == candy[j+1][i]) {
                max_temp++;
            }
            else {
                max_candy = max_candy > max_temp ? max_candy : max_temp;
                max_temp = 1;
            }
        }
        max_candy = max_candy > max_temp ? max_candy : max_temp;
    }

    return max_candy;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector< vector<char> > candy;

    cin >> N;
    for(int i=0; i<N; ++i) {
        char c;
        vector<char> temp;
        for(int j=0; j<N; ++j) {
            cin >> c;
            temp.push_back(c);
        }
        candy.push_back(temp);
    }

    int max = 1;

    // 행(row)에서 swap
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N-1; ++j) {
            if(candy[i][j] != candy[i][j+1]) {
                swap(candy[i][j], candy[i][j+1]);
                int max_temp = find_max_candy(N, candy);
                max = max > max_temp ? max : max_temp;
                swap(candy[i][j], candy[i][j+1]);
            }
        }
    }

    // 열(column)에서 swap
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N-1; ++j) {
            if(candy[j][i] != candy[j+1][i]) {
                swap(candy[j][i], candy[j+1][i]);
                int max_temp = find_max_candy(N, candy);
                max = max > max_temp ? max : max_temp;
                swap(candy[j][i], candy[j+1][i]);
            }
        }
    }

    cout << max << '\n';
    return 0;
}