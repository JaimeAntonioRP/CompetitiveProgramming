#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
const int MAXN = 1e7 + 1;
 
void solve(){
    int n, m, ans = 0; cin >> n >> m;
    while(m > n){
        if(m % 2) {
            m++;
            ans++;
        }
        m /= 2;
        ans++;
    }
    ans += (n - m);
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; t = 1;
    while(t--)solve();
    return 0;}
