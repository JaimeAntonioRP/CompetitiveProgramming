#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e5 + 10;
int a[MAXN] = {0};
void solve(){
    int n, mx = 0, ai; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ai;
        mx = max(mx, ai);
        a[ai]++;
    }
    ll dp[mx];
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i <= mx; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + (1ll * i * a[i]));
    }
    cout << dp[mx] << "\n";
}
 
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}
