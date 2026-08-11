#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    std::cin>>n;
    std::vector<std::array<int,3>>beg(n+1),ends(n+1);
    std::array<ll,3>sum,rsum;
    sum.fill(0);
    rsum.fill(0);
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            std::cin>>beg[i][j];
            sum[j]+=beg[i][j];
            if(i==1){
                sum[j]-=2ll*beg[1][j];
            }
        }
        for(int j=0;j<3;j++){
            std::cin>>ends[i][j];
            rsum[j]+=ends[i][j];
        }
    }
    int pos=0;
    ll tx=-1*(sum[0]-rsum[0])/2;
    ll ty=-1*(sum[1]-rsum[1])/2;
    ll tz=-1*(sum[2]-rsum[2])/2;
    for(int i=1;i<=n;i++){
        if(tx==ends[i][0]&&ty==ends[i][1]&&tz==ends[i][2]){
            std::cout<<i<<'\n';
            return ;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
     cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
