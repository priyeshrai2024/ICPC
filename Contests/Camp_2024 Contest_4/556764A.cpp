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

struct circle {
    ll x, y, r;
};
bool touch(circle a, circle b) {
    long double dist = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return dist <= (long double)a.r + (long double)b.r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, w;
    cin >> n >> m >> w;
    vector<circle> a(w);
    vector<bool>vis(w, false);
    for (auto &i: a) cin >> i.x >> i.y >> i.r;
    queue<circle> q;
    for (int i=0; i<w; i++) {
        if ((a[i].x<=a[i].r && a[i].y<=a[i].r) || (a[i].y + a[i].r >= m && a[i].x + a[i].r >= n)) {
            cout << 'N';
            return 0;
        }
        if (a[i].x<=a[i].r || a[i].y + a[i].r>=m) {
            q.push(a[i]);
            vis[i] = 1;
        }
    }
    char ans = 'S';
    while (!(q.empty())) {
        circle curr = q.front();
        q.pop();
        if (curr.y <= curr.r || curr.x + curr.r >= n) {
            ans = 'N';
            break;
        }
        for (int i=0; i<w; i++) {
            if (!(vis[i]) && touch(a[i], curr)) {
                q.push(a[i]);
                vis[i] = 1;
            }
        }
    }
    cout << ans;
    return 0;
}