#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e7 + 1;

bool flag(int t, string s){
    int l = 0, r;
    while(l < s.size() - 1){
        char ff = s[l], ss = s[l + 1];
        int r = l + 2;
        if(ff == 'A' + (t % 3) && ss == 'A' + (t % 2)){
            while(!(s[r] == 'A' + (t % 2) && s[r + 1] == 'A' + (t % 3)) && r < s.size() - 1) r++;
            if(r < s.size() - 1) return true;
            else l = r;
        }
        else{
            l++;
        }
    }
    return false;
}
void solve(){
    string s; cin >> s;
    int n = s.size();
    int l = 0, f = 0;
    if(flag(3, s) or flag(4, s)){
        cout << "YES";    
    }
    else{
         cout << "NO";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}
    