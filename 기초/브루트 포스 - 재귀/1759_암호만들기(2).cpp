#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> alphabet;
vector<char> pw;

class ElementExist {
    vector<char> &element;
public:
    ElementExist(vector<char> &_e) : element(_e) {}
    bool operator()(char c) const {
        if(find(element.begin(), element.end(), c) != element.end())
            return true;
        return false;
    }
};

bool is_valid(const vector<char>& s) {
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    vector<char> consonant = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

    if(any_of(s.begin(), s.end(), ElementExist(vowel)) && 
        count_if(s.begin(), s.end(), ElementExist(consonant)) >= 2)
        return true;
    return false;
}

void dfs(int depth) {
    if(depth == L) {
        if(is_valid(pw)) {
            for_each(pw.begin(), pw.end(), [](auto _c) { cout << _c; });
            cout << '\n';
        }
        return ;
    }

    else {
        for(int i=0; i<C; ++i) {
            if(depth == 0 || alphabet[i] > pw[depth-1]) {
                pw[depth] = alphabet[i];
                dfs(depth+1);
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

    dfs(0);

    return 0;
}