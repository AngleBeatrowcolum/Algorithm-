#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dsu{
    std::vector<int>fa,siz;
    
    Dsu(int n){
        fa.resize(n+1);
        siz.assign(n+1,0);
        iota(fa.begin(),fa.end(),0);
    }
    
    int find(int x){
        if(fa[x]==x){//Represent find the ancestor
            return x;
        }
        return fa[x]=find(fa[x]);
    }
    void mergy(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return;//the same ancestor
        fa[y]=x;
        siz[x]+=siz[y];
    }
};

void solve() {
    int n,x,y;
    std::cin>>n>>x>>y;
    Dsu dsu(n);
    std::vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(i+x<=n){
            dsu.mergy(i,i+x);
        }
        if(i+y<=n){
            dsu.mergy(i,i+y);
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        int u=dsu.find(i);
        int v=dsu.find(a[i]);
        if(u!=v)flag=false;
    }
    if(flag)std::cout<<"Yes"<<'\n';
    else std::cout<<"No"<<'\n';
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
