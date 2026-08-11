#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int M=1e4+10;
const ll MAXNS=1e18;
int cnt[M][8];
std::vector<int>get(int N){
    std::vector<int>r;
    for(int i=2;i*i<=N;i++){
        if(N%i==0){
            while(N%i==0)N/=i;
            r.emplace_back(i);
        }
    }
    if(N!=1)r.emplace_back(N);
    return r;
}
int gets(int x,int y){
    int m=0;
    while(x){
        if(x%y==0){
            x/=y;
            m++;
        }else{
            break;
        }
    }
    return m;
}
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<8;j++){
            cnt[i][j]=0;
        }
    }
}
void solve() {
    int n,m,V;
    std::cin>>n>>m>>V;
    std::vector<std::vector<PII>>adj(n+1);
    std::vector<int>a(n+5);
    init(n);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        std::cin>>u>>v>>w;
        if(u==v)continue;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    if(V==1){
        std::cout<<0<<'\n';
        return ;
    }
    std::vector<std::array<ll,512>>dis(n+1),vis(n+1);
    std::vector<int>se=get(V);
    std::priority_queue<std::array<ll,3>,std::vector<std::array<ll,3>>,std::greater<std::array<ll,3>>>pq;

    for(int i=1;i<=n;i++){
        vis[i].fill(false);
        dis[i].fill(MAXNS);
    }
    std::vector<int>pre;
    for(auto v:se){
        pre.emplace_back(gets(V,v));
    }
    std::vector<int>rflag(n+1,0);
    for(int i=1;i<=n;i++){
        int p=0;
        for(auto v:se){
            cnt[i][p]=gets(a[i],v);
            if(cnt[i][p]>pre[p])rflag[i]+=(1<<p);
            p++;
        }
     //   std::cout<<rflag[i]<<'\n';
    }
    ll ans=MAXNS;
    //if cnt[i][p] all is zero so the ans must be 1;
    auto dij=[&]()->void{
        pq.push({0,1,rflag[1]});
        dis[1][rflag[1]]=0;
        while(!pq.empty()){
            auto [dist,u,flag] = pq.top();
            pq.pop();
          //  std::cerr<<dist<<" "<<u<<" "<<flag<<'\n';
            if((flag==0)){
                ans=std::min(ans,dist);
            }
            if(vis[u][flag])continue;
            vis[u][flag]=true;
            for(auto [v,w]:adj[u]){
                if(dist+w<dis[v][(flag&rflag[v])]){
                    dis[v][(flag&rflag[v])]=dist+w;
                    if(!vis[v][(flag&rflag[v])]){
                        pq.push({dis[v][(flag&rflag[v])],v,(flag&rflag[v])});
                    }
                }
            }
        }
    };
    dij();
    if(ans==MAXNS){
        std::cout<<-1<<'\n';
        return ;
    }
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
