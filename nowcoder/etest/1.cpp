#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N=2e5+10;
const int Mod=1e9+7;
int dp[N];
int cnt[10];
int a[N];
void solve() {
    int n;
    std::cin>>n;
    char c;
    int ans=0;
    for(int i=0;i<n;i++){
        std::cin>>c;
        a[i]=c-'0';
    }
    memset(dp,0,sizeof(dp));
    if(a[0]!=0){
        cnt[a[0]]=1;
        if(!(a[0]&1)){
            ans++;
        }
    }
    for(int i=1;i<n;i++){
       int sum=0;
        if(a[i]==0){
            for(int j=0;j<10;j++){
                sum=(sum+cnt[j])%Mod;
            }
            ans=(ans+1)%Mod;
            cnt[0]=(cnt[0]+sum)%Mod;
            ans=(ans+sum)%Mod;
            std::cout<<sum<<" "<<" "<<ans<<'\n';
        }else if(a[i]&1){
            for(int j=0;j<10;j++){
                sum=(sum+cnt[j])%Mod;
            }
            cnt[a[i]]=(cnt[a[i]]+1+sum)%Mod;
        }else{
            for(int j=0;j<10;j++){
                sum=(sum+cnt[j])%Mod;
            }
            cnt[a[i]]=(cnt[a[i]]+1+sum)%Mod;
            ans=(ans+1)%Mod;
            ans=(ans+sum)%Mod;
           // std::cout<<a[i]<<" "<<sum<<" "<<ans<<'\n';
        }
    }
    std::cout<<ans%Mod<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
