#include <iostream>
#include <vector>

using namespace std;

int k;
long long min_v=9999999999, max_v=0;
vector<char> sign;
vector<int> number;
vector<bool> visit(10);

void dfs(int depth) {
    if(depth == k+1) {
        long long n = 0;
        for(int i=0; i<number.size(); ++i) {
            n *= 10;
            n += number[i];
        }

        min_v = n < min_v ? n : min_v;
        max_v = n > max_v ? n : max_v;

        return ;
    }

    for(int i=0; i<=9; ++i) {
        if(depth==0 || (!visit[i] && 
        (sign[depth-1]=='<' && number[depth-1]<i || sign[depth-1]=='>' && number[depth-1]>i))) {
            visit[i] = true;
            number[depth] = i;            

            dfs(depth+1);
            visit[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    sign.resize(k);
    number.resize(k+1);
    for(int i=0; i<k; ++i)
        cin >> sign[i];

    dfs(0);

    cout.fill('0');
    cout.width(k+1);
    cout << max_v << '\n';

    cout.fill('0');
    cout.width(k+1);
    cout << min_v << '\n';

    return 0;
}