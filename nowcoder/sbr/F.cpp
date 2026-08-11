#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::array<int,3>;
int n,m,k;
const int N=1e3+10;
int dis[N][11];
bool vis[N][11];
const ll MAXN=1e9;
void solve() {
    std::cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dis[i][j]=MAXN;
        }
    }
    memset(vis,false,sizeof(vis));
    std::vector<std::vector<std::pair<int,int>>>adj(n+5);
    for(int j=1;j<=m;j++){
        int u,v,w;
        std::cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    std::priority_queue<PII,std::vector<PII>,std::greater<PII> >pq;
    pq.push({0,1,0});
    dis[1][0]=0;
    while(!pq.empty()){
        PII u=pq.top();
        pq.pop();
        int dist=u[0],x=u[1],y=u[2];
       // std::cerr<<x<<" "<<y<<'\n';

        if(vis[x][y])continue;
        vis[x][y]=true;
        if(y==k){
            for(auto [v,w]:adj[x]){
                if(dis[x][y]+w<dis[v][y]){
                    dis[v][y]=dis[x][y]+w;
                    if(!vis[v][y]){
                        pq.push({dis[v][y],v,y});
                    }
                }
            }
            continue;
        }
        for(auto [v,w]:adj[x]){
            if(dis[x][y]+w<dis[v][y]){
                dis[v][y]=dis[x][y]+w;
                if(!vis[v][y]){
                    pq.push({dis[v][y],v,y});
                }
            }
            if(dis[x][y]<dis[v][y+1]){
                dis[v][y+1]=dis[x][y];
                if(!vis[v][y+1]){
                    pq.push({dis[v][y+1],v,y+1});
                }
            }
        }
    }
    int ans=MAXN;
    for(int i=0;i<=k;i++){
        ans=std::min(dis[n][i],ans);
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
