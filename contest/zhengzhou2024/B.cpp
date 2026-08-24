#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int N=2e5+10;
int mx[N];
int a[N];
const int MAXN=1e9;
void solve() {
   int n;
   std::cin>>n;
   for(int i=1;i<=n;i++){
       std::cin>>a[i];
   }
   mx[n+1]=MAXN;
   for(int i=n;i>=1;i--){
       mx[i]=std::min(mx[i+1],a[i]);
   }
   int pre=0;
   ll ans=0;
   for(int i=1;i<=n;i++){
       ++pre;
       if(mx[i]==a[i]){
          ans+=pre/a[i];
          pre%=a[i];
       }
   }
   std::cout<<ans<<'\n';
   
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
