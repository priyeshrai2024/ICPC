#include <bits/stdc++.h>
using namespace std;

static int digitOf[26];

int main(){
    string groups[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(int g = 0; g < 8; ++g)
        for(char c : groups[g]) digitOf[c-'a'] = g + 2;

    int N, M;
    scanf("%d %d", &N, &M);

    vector<string> names(N);
    long long totalNameLen = 0;
    for(int i = 0; i < N; ++i){
        static char buf[100005];
        scanf("%s", buf);
        names[i] = buf;
        totalNameLen += (long long)names[i].size();
    }

    int maxNodes = (int)totalNameLen + 2;
    vector<array<int,10>> child(maxNodes);
    for(auto &a : child) a.fill(-1);
    vector<int> cnt(maxNodes, 0);

    int nodeCount = 1; // node 0 = root

    for(int i = 0; i < N; ++i){
        int cur = 0;
        for(char c : names[i]){
            int d = digitOf[c - 'a'];
            if(child[cur][d] == -1){
                child[cur][d] = nodeCount++;
            }
            cur = child[cur][d];
            cnt[cur]++;
        }
    }

    string out;
    out.reserve(1 << 20);

    for(int i = 0; i < M; ++i){
        static char buf[100005];
        scanf("%s", buf);
        int len = (int)strlen(buf);
        int cur = 0;
        bool ok = true;
        for(int j = 0; j < len; ++j){
            int d = buf[j] - '0';
            if(child[cur][d] == -1){ ok = false; break; }
            cur = child[cur][d];
        }
        long long ans = ok ? cnt[cur] : 0;
        out += to_string(ans);
        out += '\n';
    }

    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}