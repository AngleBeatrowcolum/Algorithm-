#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
const int N=105;
bool f[N][N];
int p[N*2];
bool vis[N*2];
int M;
bool g[N][N*2];
bool match(int i){
    for(int j=M+1;j<=M*2;j++){
        if(g[i][j]&&!vis[j]){
            vis[j]=true;
            if(p[j]==0||match(p[j])){
                p[j]=i;
                return true;
            }
        }
    }
    return false;
}
int berge(){
    int cnt=0;
    for(int i=1;i<=M;i++){
        memset(vis,0,sizeof(vis));
        if(match(i))cnt++;
    }
    return cnt;
}
void solve() {
     int n,m;
     std::cin>>n>>m;
     memset(f,false,sizeof(f));
     memset(g,false,sizeof(g));
     memset(p,0,sizeof(p));

     for(int j=1;j<=m;j++){
        int u,v;
        std::cin>>u>>v;
        f[u][v]=true;
     }
     for(int i=1;i<=n;i++){
        f[i][i]=true;
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(f[i][k]&&f[k][j]){
                    f[i][j]=true;
                }
            }
        }
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j]&&i!=j){
                g[i][j+n]=true;
            }
        }
     }
     M=n;
     int k=berge();
     std::cout<<n-k<<'\n';
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
