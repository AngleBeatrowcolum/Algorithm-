#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::array<ll,3>;
using ull = unsigned long long;
using uint = unsigned int;
using uint8=__int128;
const ll MAXN=1e18;
uint8 cal(ll n){
    uint8 p=n;
    return p*(p+1)*(2*p+1)/6;
    
}
void solve() {
   ll n,m,k;
   std::cin>>n>>m>>k;
   ll l=-MAXN,r=MAXN;
   auto check=[&](ll mid)->bool{
      ll ks=0;
      for(ll i=1;i<=n;i++){
         if(i*i-mid<=0){
            continue;
         }else{
            ll p=sqrt(i*i-mid);
            ks+=std::min(p,m);
         }
      }
      if(ks>=k){
        return true;
      }else{
        return false;
      }
   };
   ll pos;
   while(l<=r){
      ll mid=(l+r)>>1;
      if(check(mid)){
         l=mid+1;
         pos=mid;
      }else{
        r=mid-1;
      }
   }
   ll ans=0;
   for(ll i=1;i<=n;i++){
     if(i*i-pos<=0)continue;
     ll p=sqrt(i*i-pos);
     p=std::min(p,m);
     uint8 ps=p*i*i;
     uint8 qs=cal(p);
     ans+=ps-qs;
   }   
    ll ks=0;
      for(ll i=1;i<=n;i++){
         if(i*i-pos<=0){
            continue;
         }else{
            ll p=sqrt(i*i-pos);
            ks+=std::min(p,m);
         }
      }
      if(ks>k){
        ans-=(ks-k)*pos;
        std::cout<<ans<<'\n';
      }else{
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
