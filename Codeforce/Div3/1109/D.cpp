#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n,m;
    std::cin>>n>>m;
    std::vector<int>a(n+1);
    std::vector<ll>sum(n+1);

    sum[0]=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    std::vector<int>b(m);
    
    for(int j=0;j<m;j++){
        std::cin>>b[j];
    }
    std::sort(b.begin(),b.end());
    
    if(m==1){
        std::cout<<abs(sum[b[0]])+sum[n]-sum[b[0]]<<'\n';
    }else{
        ll ans=sum[n]-sum[b.back()];
        for(int i=b.size()-1;i>0;i--){
            int r=b[i],l=b[i-1];
            ans+=abs(sum[r]-sum[l]);
        }
        ans+=abs(sum[b[0]]);
        std::cout<<ans<<'\n';
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
