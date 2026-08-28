#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
    int n;
    std::cin>>n;
    std::vector<int>fa(n+1),a(n+1);
    std::vector<int>flag(n+1),siz(n+1),cnt(n+1,0);
    std::vector<std::vector<int>>adj(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    flag[1]=1;
   int ans=0; 
   auto dfs=[&](auto &&self,int u,int fas)->void{
     
       for(auto v:adj[u]){
          if(v==fas)continue;
          cnt[u]++;
          if(2*a[v]>=a[u]){
             flag[v]=true;
          }else{
             flag[v]=false;
          }
          self(self,v,u);
          flag[u]=(flag[u]&flag[v]);
          siz[u]+=flag[v]?1:0;
       }
   };
  
   auto cal=[&](int u,int v)->void{
      cnt[u]--;
      siz[u]-=flag[v]?1:0;
      flag[u]=(siz[u]==cnt[u]&&(a[u]*2>=a[v]))?true:false;
      cnt[v]++;
      siz[v]+=(flag[u])?1:0;
      flag[v]=(siz[v]==cnt[v])?true:false;
   };
   auto dfs1=[&](auto &&self,int u,int fas)->void{
       for(auto v:adj[u]){
         if(v==fas)continue;
         cal(u,v);
         ans+=flag[v]?1:0;
         self(self,v,u);
         cal(v,u);
       }
   };
   dfs(dfs,1,0);
   ans=flag[1]?1:0;
   dfs1(dfs1,1,0);
   std::cout<<ans<<'\n';
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
