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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ll na = 0, nb = 0;
    vll psa(sz(s) + 1, 0), psb(sz(s) + 1, 0);
    for(ll i = 1; i <= sz(s); i ++) {

        psa[i] = psa[i-1];
        psb[i] = psb[i-1];

        if(s[i-1] == 'A') 
        {
            na ++;
            psa[i] ++;
        }
        else 
        {
            nb ++;
            psb[i] ++;
        }
        
    }
    // bool is_true = true;
    ll ans_a = 0,ans_b=0;
    if(na % 2 != 0 || nb % 2 != 0) cout << "NO" << endl;
    else {
        
        for(ll i = 0, j = (na / 2 + nb / 2); j <= sz(s); i ++, j ++) {
            if((psa[j] - psa[i] == na/2) && (psb[j] - psb[i] == nb/2))
            {
                ans_a = i+1;
                ans_b = j;
                break;
            }
        }

        cout<<"YES\n";
        cout<<ans_a<<" "<<ans_b+1<<endl;
    }
    return 0;
}