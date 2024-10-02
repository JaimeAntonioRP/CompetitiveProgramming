#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e5 + 10;
int a[MAXN]; 
void solve(){
    int n, t; cin >> n >> t;
    for(int i = 0; i < n; i++) cin >> a[i + 1]; 
    a[0] = 0;
    ll s = 0;
    int ans = 0, l = 0, r = l + 1;
    while(r <= n){
        s -= a[l];
        l++;
        while((s + a[r] <= t) && r <= n){
            s += a[r];
            r++;   
        }
        ans = max(ans, r - l);
    }
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}
