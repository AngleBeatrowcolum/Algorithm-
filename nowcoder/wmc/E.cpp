#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::array<int,3>;
using ull = unsigned long long;
using uint = unsigned int;
const int MAXN=1e9;
bool vis[1005][1005][3];
int dis[1005][1005][3];
void init(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<3;k++){
                vis[i][j][k]=false;
                dis[i][j][k]=MAXN;
            }
        }
    }
}
int dx[]={0,0,0,0,0,0,1,-1,2,-2,-3,3};
int dy[]={1,-1,2,-2,3,-3,0,0,0,0,0,0};
void solve() {
    int n,m;
    std::cin>>n>>m;
    std::string s;
    std::cin>>s;
    std::array<int,3>pq;
    init(n,m);
    int pre=(s[0]-'a')*100+(s[1]-'a')*10+(s[2]-'a');
    int rpre=(s[1]-'a')*100+(s[2]-'a')*10+(s[0]-'a');
    int ppre=(s[2]-'a')*100+(s[0]-'a')*10+(s[1]-'a');
    dis[n][m][0]=dis[n][m][1]=dis[n][m][2]=0;
    pq[0]=pre,pq[1]=rpre,pq[2]=ppre;
    std::vector<std::vector<int>>a(n+1,std::vector<int>(m+1));
   
    int cnt=0;
    for(int i=1;i<=n;i++){
        char c;
        for(int j=1;j<=m;j++){
            std::cin>>c;
            a[i][j]=c-'a';
        }
    }
    auto bfs=[&]()->void{
        std::queue<PII>q;
        q.push({n,m,0}),q.push({n,m,1}),q.push({n,m,2});
        while(!q.empty()){
            auto [x,y,pos]=q.front();
            q.pop();
            if(vis[x][y][pos]){
                continue;
            }
    
            vis[x][y][pos]=true;
            for(int i=0;i<12;i++){
                int px=x+dx[i],py=y+dy[i];
                if(px>n||px<=0||py>m||py<=0)continue;
                int pps=(pos+2)%3;
                int r=std::max(abs(dx[i]),abs(dy[i]))-1;
                std::array<int,3>rs;
                int cns=0;
                int tk=pq[pps];
                while(cns<3){
                    rs[2-cns]=tk%10;
                    tk/=10;
                    cns++;
                }
                if(rs[r]!=a[x][y])continue;
                if(dis[px][py][pps]>dis[x][y][pos]+1){
                    dis[px][py][pps]=dis[x][y][pos]+1;
                    if(!vis[px][py][pps]){
                        q.push({px,py,pps});
                    }
                }
            }
        }
    };
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[i][j][0]==MAXN)std::cout<<-1<<" ";
            else{
                std::cout<<dis[i][j][0]<<' ';
            }
        }
        std::cout<<'\n';
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
