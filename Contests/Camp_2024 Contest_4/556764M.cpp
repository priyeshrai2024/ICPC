#include <bits/stdc++.h>
using namespace std;
using ll=long long; using ull=unsigned long long; using db=long double;
using vi=vector<int>; using vll=vector<ll>; using pll=pair<ll,ll>;
using vpll=vector<pll>; using mll=map<ll,ll>; using sll=set<ll>;
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) (ll)(v).size()
#define FOR(a,b,i)  for(ll i=(a);i<(b);i++)
#define FORE(a,b,i) for(ll i=(a);i<=(b);i++)
#define RFOR(a,b,i) for(ll i=(a);i>=(b);i--)
#define YES cout<<"YES\n"
#define NO  cout<<"NO\n"
#define endl '\n'
const ll MOD=1e9+7, MOD2=998244353, INF=1e11;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n);
    FOR(0, n, i) cin >> a[i];
    ll l = 1, r = INF;
    ll ans = -1;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll j = 0;
        FOR(0, m, i) {
            ll curr = 0;
            ll md = mid * k;
            while((j < n) && ((curr + a[j]) <= md)) {
                curr += a[j];
                j ++;
            }
            if(j == n) break;
        }
        if(j >= n) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}