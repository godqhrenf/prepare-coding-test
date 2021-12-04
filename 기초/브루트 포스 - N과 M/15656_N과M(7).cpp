#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> input_num; // N개의 숫자
vector<int> nums; // 수열

void dfs(int depth) {
    if(depth == M) {
        for_each(nums.begin(), nums.end(), [](auto _x) { cout << _x << ' '; });
        cout << '\n';
    }
    else {
        for(int i=0; i<N; ++i) {
            nums[depth] = input_num[i];
            dfs(depth+1);
        }
    }
}

int main(void) {
    cin >> N >> M;
    while(cin >> num)
        input_num.push_back(num);
    sort(input_num.begin(), input_num.end()); // 오름차순으로 정렬

    // 배열 사이즈 정해줌
    nums.resize(M);

    dfs(0);

    return 0;
}