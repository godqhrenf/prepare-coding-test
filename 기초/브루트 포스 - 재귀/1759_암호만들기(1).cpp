#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alphabet;
vector<char> pw;

void dfs(int depth, int vowel, int consonant) {
    if(depth == L) {
        if(vowel >= 1 && consonant >= 2) {
            for_each(pw.begin(), pw.end(), [](auto _c) { cout << _c; });
            cout << '\n';
        }
        return ;
    }

    else {
        for(int i=0; i<C; ++i) {
            if(depth == 0 || alphabet[i] > pw[depth-1]) {
                pw[depth] = alphabet[i];
                if(alphabet[i]=='a' || alphabet[i]=='e' || alphabet[i]=='i' || alphabet[i]=='o' || alphabet[i]=='u')
                    dfs(depth+1, vowel+1, consonant);
                else
                    dfs(depth+1, vowel, consonant+1);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a;
    cin >> L >> C;
    while(cin >> a)
        alphabet.push_back(a);
    sort(alphabet.begin(), alphabet.end());
    pw.resize(L);

    dfs(0, 0, 0);

    return 0;
}