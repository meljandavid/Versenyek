#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

using ll=long long;
const ll MOD = 1e9+7;
const int BASE=31;

ll qpow(int a, int b) {
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    ll r=qpow(a, b/2);
    if(b%2 == 0) return (r*r % MOD);
    r = (r*r) % MOD;
    return ((r*a) % MOD);
}

ll chash(char c, int p) {
    return ((c-'a') * qpow(BASE, p) % MOD);
}

ll genhash(const string& s, int spos=0) {
    ll h=0, p=1;
    for(int i=0; i<s.size(); i++) {
        int pos = ( (i+spos) % s.size());
        h = ( h + chash(s[pos], pos) ) % MOD;
        p = (p*BASE) % MOD;
    }
    return h;
}

ll genhash2(const string& s) {
    ll h=0, p=1;
    for(int i=0; i<s.size(); i++) {
        h = (h + p*(s[i]-'a')) % MOD;
        p = (p*BASE) % MOD;
    }
    return h;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int N,M; cin>>N>>M;
    vector<string> t(N);
    for(string& s : t) cin>>s;

    unordered_map<ll,int> hashes;

    if(M>=1000) {
        for(int i=0; i<t.size(); i++) {
            ll minh=LLONG_MAX;
            ll h = genhash(t[i], 0);

            for(int j=M-1; j>0; j--) {
                h = (h + MOD - chash(t[i][j], M-1)) % MOD;
                h = (h*BASE) % MOD;
                h = (h + chash(t[i][j], 0)) % MOD;

                if(h<minh) minh=h;
            }
            hashes[minh]++;
        }
    } else {
        for(int i=0; i<t.size(); i++) {
            string s=t[i];
            string first = s;
            for(int j=0; j<s.size(); j++) {
                string shuffled = s.substr(j) + s.substr(0, j);
                if(shuffled<first) first=shuffled;
            }
            t[i]=first;
        }

        for(const string& s : t) {
            hashes[genhash2(s)]++;
        }
    }

    int ans=0;
    for(const pair<ll,int>& p : hashes) {
        int o=p.second;
        ans += o*(o-1)/2;
    }
    cout<<ans<<endl;

    return 0;
}
