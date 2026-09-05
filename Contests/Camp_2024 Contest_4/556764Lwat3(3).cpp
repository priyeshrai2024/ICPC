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

string solve(ll n) {
    string ans;
    while (n) {
        ans = (char)((n&1) + '0') + ans;
        n >>=1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    string bin = solve(n);
    ll curr = 0;
    ll ans = 0;
    for (int i=0; i<(int)bin.size(); i++) {
        if(bin[i] == '1')++curr;
        else
        {
            ans += (1LL<<curr);
            curr = 0;
        } 
    }

    if(curr)ans += (1LL<<curr);

    cout<<ans;
    return 0;
}