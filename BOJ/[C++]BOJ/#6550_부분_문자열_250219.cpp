#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s, t;
    while(cin >> s >> t) {
        bool check = false;
        int sIdx = 0;
        for(int i=0; i<t.length(); i++){
            if(s[sIdx] == t[i]) sIdx++;
            if(sIdx == s.length()) check = true;
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}
