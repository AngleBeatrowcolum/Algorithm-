#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+10;
const int MAXN=1e6+1;
int fa[N],a[N];
int pos[1000005];
std::array<std::vector<int>,MAXN>vec;
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);   
}
void mergy(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return ;
    fa[y]=x;
}
void solve() {
    int n;
    std::cin>>n;
    int maxx=0;
    memset(pos,0,sizeof(pos));
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        pos[a[i]]=i;
        maxx=std::max(a[i],maxx);
    }
    
    for(int i=1;i<=maxx;i++){
        for(int j=i;j<=maxx;j+=i){
             if(pos[j])vec[i].emplace_back(pos[j]);
        }
    }
    ll ans=0;
    for(int i=maxx;i>=1;i--){
        if(vec[i].size()<=1)continue;
        int u=vec[i].back();
        int p=find(u);
        vec[i].pop_back();
        for(auto v:vec[i]){
            int q=find(v);
            if(p!=q){
                mergy(p,q);
                ans+=i;
            }
            
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
