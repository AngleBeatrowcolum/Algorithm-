#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int N=2e5+10;
const ll MAXN=1e12;
ll mx[N];
int a[N];
ll cal(int x){
    return 1ll*x*x*x*x;
}
void solve() {
   int n,m;
   std::cin>>n>>m;
   for(int i=1;i<=m;i++){
       std::cin>>a[i];
   } 
   for(int i=1;i<=n;i++){
      mx[i]=MAXN;
   }
   mx[0]=0;
   for(int i=1;i<=m;i++){//now How many Bug have
       for(int j=1;j<=380;j++){
           if(i<j)break;
           mx[a[i]]=std::min(mx[a[i]],mx[a[i-j]]+cal(j)+a[i]);
       }
   }
   std::cout<<mx[a[m]]<<'\n';
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
