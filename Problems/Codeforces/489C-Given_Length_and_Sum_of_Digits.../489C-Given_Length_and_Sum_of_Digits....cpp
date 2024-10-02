#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e7 + 1;

string maxnum(int m, int s){
    string mx(m, '0');
    for(int i = 0; i < m; i++){
        mx[i] = (min(9, s) + '0');
        s -= min(9, s);
        if(s == 0) break;
    }
    return mx;
}

string minum(int m, int s){
    string mn(m, '0');
    mn[0] = max(1,  s - ((m - 1)* 9)) + '0';
    string mx = maxnum(m - 1, s - (mn[0] - '0'));
    for(int i = 1; i < m; i++){
        mn[i] = mx[m - 1 - i];
    }
    return mn;
}
 
void solve(){
    int m, s; cin >> m >> s;
    if(m == 1 && s == 0) cout << 0 << " " << 0;
    else if(m * 9 < s || 1 > s){
        cout << - 1 << " " << - 1;
    }
    else{
        cout << minum(m, s) << " " << maxnum(m, s) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}