#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int Mod=998244353;
int qpow(int x,int y){
    int r=1;
    while(y){
        if(y&1){
            r=1ll*x*r%Mod;
        }
        y>>=1;
        x=1ll*x*x%Mod;
    }
    return r;
}
struct lca{
    int n,tot;
    std::vector<std::vector<int>>g;
    
    std::vector<int>dep;
    std::vector<int>fi;
    std::vector<int>euler;
    
    
    std::vector<int>lg;
    std::vector<std::vector<int>>st;
    
    lca(int _n){
        n=_n;
        g.assign(n+1,{});
        dep.resize(n+1);
        fi.resize(n+1);
        euler.resize(2*n+1);
        tot=0;
    }
    void add(int u,int v){
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void dfs(int u,int fa){
        fi[u]=++tot;
        euler[tot]=u;
        for(int v:g[u]){
            if(v==fa)continue;
            dep[v]=dep[u]+1;
            dfs(v,u);
            euler[++tot]=u;
        }
    }
    void build(int root=1){
        dep[root]=0;
        dfs(root,0);
        lg.assign(tot+1,0);
        for(int i=2;i<=tot;i++){
            lg[i]=lg[i>>1]+1;
        }
        int Log=lg[tot]+1;
        st.assign(Log,std::vector<int>(tot+1));
        
        for(int i=1;i<=tot;i++){
            st[0][i]=euler[i];
        }
        for(int k=1;k<Log;k++){
            int len=(1<<k);
            int hlen=len>>1;
            for(int i=1;i+len-1<=tot;i++){
                int x=st[k-1][i];
                int y=st[k-1][i+hlen];
                st[k][i]=dep[x]<dep[y]?x:y;
            }
        }
    }
    int rmq(int l,int r)const{
        if(l>r)std::swap(l,r);
        int k=lg[r-l+1];
        
        int x=st[k][l];
        int y=st[k][r-(1<<k)+1];
        return dep[x]<dep[y]?x:y;
    }
    int dlca(int u,int v)const{
        return rmq(fi[u],fi[v]);
    }
    int dist(int u,int v)const{
        int p=dlca(u,v);
        return dep[u]+dep[v]-2*dep[p];
    }
};
void solve() {
   int n;
   std::cin>>n;
   int u,v;
   lca d(n);
   
   for(int i=1;i<n;i++){
      std::cin>>u>>v;
      d.add(u,v);
   }
   d.build();
   std::vector<int>vec;
   
   auto ddfs=[&](auto &&self,int u,int fa)->void{
       if(d.g[u].size()==1&&u!=1){
          vec.emplace_back(u);
          return ;
       }
       for(auto v:d.g[u]){
          if(v==fa)continue;
          self(self,v,u);
       }
   };
   ddfs(ddfs,1,0);
   auto cmp=[&](PII &a,PII &b)->bool{
      return a.first*b.second>a.second*b.first;
   };
  
   std::vector<PII>rans;
   for(int i=0;i<vec.size();i++){
    std::vector<PII>ans;
      for(int j=0;j<vec.size();j++){
        if(j==i)continue;
        int u=vec[i],v=vec[j];
        std::cerr<<u<<" "<<v<<'\n';
        int y=d.dist(u,v),x=d.dist(d.dlca(u,v),v);
        
        PII dk={x,y};
        if(ans.empty()){
            ans.emplace_back(dk);
        }else{
            if(cmp(ans.back(),dk)){
                ans.pop_back();
                ans.emplace_back(dk);
            }
        }
      }
      if(!ans.empty())
      rans.emplace_back(ans[0]);
   }
   PII ansx=rans.back();
   rans.pop_back();
   while(!rans.empty()){
      std::cerr<<ansx.first<<" "<<ansx.second<<" "<<rans.back().first<<" "<<rans.back().second<<'\n';
      if(cmp(rans.back(),ansx)){
         ansx=rans.back();
      }
      rans.pop_back();
   }
   //std::cout<<ansx.first<<" "<<ansx.second<<'\n';
   std::cout<<1ll*ansx.first*qpow(ansx.second,Mod-2)%Mod<<'\n';
   
    
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
