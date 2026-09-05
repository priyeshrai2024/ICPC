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

ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

vll fact, invFact;

void precompute(ll n) {
    fact.assign(n + 1, 1);
    invFact.assign(n + 1, 1);
    for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = power(fact[n], MOD - 2, MOD);
    for (ll i = n - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    
    precompute(n + 1);
    ll ans2 = 0;
    FOR(2, n + 1, i) {
        if (i % 2 == 0) {
            ans2 += ((fact[n] * invFact[i]) % MOD) ,ans2 %= MOD;
        } else ans2 -= ((fact[n] * invFact[i]) % MOD), ans2 += MOD, ans2 %= MOD;
    }
    cout << ans2 << endl;
    return 0;
}