#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int year;
    for(year=1; !((year-E)%15==0 && (year-S)%28==0 && (year-M)%19==0); ++year) ;
    

    cout << year << '\n';
    
    return 0;
}