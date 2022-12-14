#include<iostream>
#include<vector>
using namespace std;

using ll = long long;

int main() {
    int N; cin>>N;
    vector<int> h(N), v(N);
    for(int& i : h) cin>>i;
    for(int& i : v) cin>>i;

    ll htotal=0, vtotal=0;
    for(int i : h) htotal+=i;
    for(int i : v) vtotal+=i;

    cout<< (htotal < vtotal ? "Hamilton" : "Verstappen")<<endl;

    int hmin=1000000;

    for(int i : h) {
        if(i<hmin) hmin=i;
    }

    int vmin=1000000;
    for(int i : v) {
        if(i<vmin) vmin=i;
    }

    cout<< (hmin < vmin ? "Hamilton" : "Verstappen")<<endl;


    return 0;
}
