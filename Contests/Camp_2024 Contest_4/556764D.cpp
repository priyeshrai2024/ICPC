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
const ll MOD=1e9+7, MOD2=998244353, INF=1e18;

ll dfs(vector<vll> &child, ll node, vll &vec) {
    if(sz(child[node]) == 0) return 1;
    ll num = 0;
    for(auto c : child[node]) {
        ll curr = dfs(child, c, vec);
        if(curr > num) {
            if(num != 0) vec.pb(num);
            num = curr;
        } else vec.pb(curr);
    }
    return num + 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vll p(n + 1, 0);
    vector<vll> child(n + 1);
    FOR(2, n + 1, i) {
        ll t;
        cin >> t;
        p[i] = t;
        child[t].pb(i);
    }
    vll vec;
    ll temp = dfs(child, 1, vec);
    vec.pb(temp);
    sort(all(vec));
    reverse(all(vec));
    ll ans = 0;
    FOR(0, min(sz(vec), k), i) {
        ans += vec[i];
    }
    cout << ans << endl;
    return 0;
}