#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, C; cin>>N>>C;
    vector<int> t(N);
    for(int& i : t) cin>>i;

    vector<int> cnt(C, 0);

    int r=0, dis=0;
    int sol=N+1;
    for(int l=0; l<N; l++) {
        while(dis != C && r<N) {
            if(cnt[t[r]] == 0) dis++;
            cnt[t[r]]++;
            r++;
        }

        if(dis!=C) break;

        int len=r-l;
        if(len<sol) sol=len;

        cnt[t[l]]--;
        if(cnt[t[l]]==0) dis--;
    }
    cout<<sol<<endl;

	return 0;
}
