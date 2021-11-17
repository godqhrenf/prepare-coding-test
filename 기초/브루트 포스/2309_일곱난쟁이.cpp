#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    // C++에서 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h;
    vector<int> heights;
    while(cin >> h)
        heights.push_back(h);
    
    sort(heights.begin(), heights.end()); // 오름차순으로 정렬

    int sum = 0;
    for(auto &_x : heights)
        sum += _x;

    int i, j;
    bool flag = false; // 중첩 for문을 한 번에 빠져나오기 위한 flag
    for(i=0; i<heights.size() && !flag; ++i)
        for(j=i+1; j<heights.size(); ++j)
            if(sum-heights[i]-heights[j] == 100) {
                flag = true;
                break;
            }

    for(int k=0; k<heights.size(); ++k)
        if(k!=i-1 && k!=j) // 바깥 for문의 증가연산자로 i가 증가하므로 i-1을 해주어야 함
            cout << heights[k] << '\n';


    return 0;
}