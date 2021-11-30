#include <iostream>

using namespace std;

int find_gcd(int a, int b) {
    if(a%b == 0)
        return b;
    else
        return find_gcd(b, a%b);
}

int find_lcm(int a, int b) {
    int gcd = find_gcd(a, b);
    return a * b / gcd;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, M, N, x, y;
    cin >> T;
    while(cin >> M >> N >> x >> y) {
        int year, last_year;
        if(M >= N) {
            last_year = find_lcm(M, N);
            for(year=x; year<=last_year && !((year-y)%N==0); year+=M) ;
        }
        else {
            last_year = find_lcm(N, M);
            for(year=y; year<=last_year && !((year-x)%M==0); year+=N) ;
        }

        if(!(year<=last_year))
            cout << -1 << '\n';
        else
            cout << year << '\n';
    }
    
    return 0;
}