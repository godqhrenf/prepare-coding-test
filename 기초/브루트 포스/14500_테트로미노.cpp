#include <iostream>

using namespace std;

int N, M;
int board[500][500];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j)
            cin >> board[i][j];

    int shape = 0;
    int max = 0;

    // ─
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M-3; ++j) {
            shape = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
            max = max > shape ? max : shape;
        }
    }

    // │
    for(int i=0; i<N-3; ++i) {
        for(int j=0; j<M; ++j) {
            shape = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
            max = max > shape ? max : shape;
        }
    }

    // □
    for(int i=0; i<N-1; ++i) {
        for(int j=0; j<M-1; ++j) {
            shape = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
            max = max > shape ? max : shape;
        }
    }

    for(int i=0; i<N-2; ++i) {
        for(int j=0; j<M-1; ++j) {
            // 세로 └
            shape = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+2][j+1];
            max = max > shape ? max : shape;

            // 세로 ┘
            shape = board[i+2][j] + board[i+2][j+1] + board[i+1][j+1] + board[i][j+1];
            max = max > shape ? max : shape;

            // 세로 ┐
            shape = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+2][j+1];
            max = max > shape ? max : shape;

            // 세로 ┌
            shape = board[i][j+1] + board[i][j] + board[i+1][j] + board[i+2][j];
            max = max > shape ? max : shape;

            // 세로 계단1
            shape = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
            max = max > shape ? max : shape;

            // 세로 계단2
            shape = board[i][j+1] + board[i+1][j+1] + board[i+1][j] + board[i+2][j];
            max = max > shape ? max : shape;

            // ├
            shape = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+1][j+1];
            max = max > shape ? max : shape;

            // ┤
            shape = board[i][j+1] + board[i+1][j+1] + board[i+2][j+1] + board[i+1][j];
            max = max > shape ? max : shape;
        }
    }

    for(int i=0; i<N-1; ++i) {
        for(int j=0; j<M-2; ++j) {
            // 가로 └
            shape = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2];
            max = max > shape ? max : shape;
            
            // 가로 ┘
            shape = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+2];
            max = max > shape ? max : shape;

            // 가로 ┐
            shape = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2];
            max = max > shape ? max : shape;

            // 가로 ┌
            shape = board[i+1][j] + board[i][j] + board[i][j+1] + board[i][j+2];
            max = max > shape ? max : shape;

            // 가로 계단1
            shape = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];
            max = max > shape ? max : shape;

            // 가로 계단2
            shape = board[i+1][j] + board[i+1][j+1] + board[i][j+1] + board[i][j+2];
            max = max > shape ? max : shape;

            // ┬
            shape = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1];
            max = max > shape ? max : shape;

            // ┴
            shape = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1];
            max = max > shape ? max : shape;
        }
    }

    cout << max << '\n';

    return 0;
}