#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int Mod=998244353;
const int M=3e5+10;
int qpow(int x,int y){
    int r=1;
    while(y){
        if(y&1){
            r=1ll*r*x%Mod;
        }
        y>>=1;
        x=1ll*x*x%Mod;
    }
    return r%Mod;
}
int a[M];
void solve() {
     int n,k;
     std::cin>>n>>k;
     int ans=0;
     int sum=0;
     for(int i=1;i<=n;i++){
        std::cin>>a[i];
        ans=(ans+1ll*a[i]*a[i]%Mod)%Mod;
        sum=(sum+1ll*a[i]%Mod)%Mod;
     }
     sum=(1ll*sum*sum)%Mod;
     if(n==1){
        std::cout<<1ll*a[1]*a[1]%Mod;
        return ;
     }
     int N=qpow(n,Mod-2);
     int E1=1ll*k*N%Mod*ans%Mod;
     int N2=qpow(n-1,Mod-2);
     int N3=1ll*N*N2%Mod;
     int N4=1ll*k*(k-1)%Mod*N3%Mod;
     int num=(1ll*sum-ans+Mod)%Mod;
     int E2=1ll*N4*num%Mod;
     int E3=(1ll*E1+E2)%Mod;
     int o=1;
     for(int i=1;i<=n;i++){
        o=1ll*o*i%Mod;
     }
     int s=1;
     for(int i=1;i<=k;i++){
        s=1ll*s*i%Mod;
     }
     int m=1;
     for(int i=1;i<=n-k;i++){
        m=1ll*m*i%Mod;
     }
     int t1=qpow(s,Mod-2),t2=qpow(m,Mod-2);
     int E4=1ll*o*t1%Mod*t2%Mod;
     int ansx=1ll*E3*E4%Mod;
     std::cout<<ansx<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
