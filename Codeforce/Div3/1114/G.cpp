#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
bool cmp(const int &a,const int &b){
    return a>b;
}
void solve() {
    int n;
    std::cin>>n;
    std::vector<int>a(n+1);
    
    std::vector<int>fa(n+1),vis(n+1);
    
    std::vector<std::vector<int>>adj(n+1);

    for(int j=1;j<=n;j++){
        std::cin>>a[j];
    }
    
    for(int j=2;j<=n;j++){
        std::cin>>fa[j];
        adj[fa[j]].emplace_back(j);
        adj[j].emplace_back(fa[j]);
    }
    std::vector<std::multiset<int>>maxs(n+1);
    std::vector<int>lean;
    std::vector<int>p(n+1);
    int cnt=0;
    auto dfs=[&](auto &&self,int u,int pre)->void{
         if(adj[u].size()==1&&u!=1){
            cnt++;
            p[u]=u;
            maxs[u].insert(a[u]);
            return ;
         }
         int mins=0,k;
         for(auto v:adj[u]){
             if(v==pre)continue;
             self(self,v,u);
             if(mins<maxs[p[v]].size()){
                mins=maxs[p[v]].size();
                k=v;
             }
         }
        // std::cerr<<k<<" ";
         for(auto v:adj[u]){
            if(v==pre||v==k)continue;
            for(auto z:maxs[p[v]]){
                maxs[p[k]].insert(z);
            }
         }
         p[u]=p[k];
         int ak=*maxs[p[k]].begin();
         maxs[p[k]].insert(a[u]);
         lean.emplace_back(*maxs[p[k]].begin());
         maxs[p[k]].erase(maxs[p[k]].begin());
         return;
    };
    //every time to keep maxs all leaf number
    dfs(dfs,1,0);
    int ps=0;
    ll sum=0;
    for(auto v:maxs[p[1]]){
        sum+=v;
    }
    std::cout<<'\n';
    std::sort(lean.begin(),lean.end(),cmp);
    std::vector<ll>ansx(n+1);
    for(int i=1;i<=n;i++){
        if(i<cnt)ansx[i]=-1;
        else if(i==cnt){
            ansx[i]=sum;
        }else{
           // std::cerr<<lean[ps]<<" "; 
            ansx[i]=sum+lean[ps];
            sum=ansx[i];
            ps++;
        }
    }
    
    for(int i=1;i<=n;i++){
        std::cout<<ansx[i]<<" ";
    }
    std::cout<<'\n';
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
