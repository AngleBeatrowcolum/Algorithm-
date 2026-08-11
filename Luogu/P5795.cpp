#include<bits/stdc++.h>
using PII=std::pair<uint,int>;
using ll=long long;
const int Bit=32;
const int N=5e5+10;
const int MAXN=1e6+10;
const int M=3e7;
uint a[N];
uint xors[N];
int root[MAXN];
int cnt[M*2+5];
int tr[M][2];
//use root[i] to search the latest version for i
int idx=0;
int vis[MAXN];//to the max;
void init(){
    idx=0;
    root[0]=0;
    memset(tr,0,sizeof(tr));
}
//I also need to check the number belong who?
int modify(int pre,uint x,int delta){
    int root=++idx;
    int now=root;
    cnt[now]=cnt[pre]+delta;
    for(int i=31;i>=0;i--){
        int u=(x>>i)&1ll;
        tr[now][u^1]=tr[pre][u^1];
        tr[now][u]=++idx;
        pre=tr[pre][u];
        now=tr[now][u];
        cnt[now]=cnt[pre]+delta;
    }
    return root;
}
uint query(int root,uint x){
    int now=root;
    uint ans=0;
    for(int j=31;j>=0;j--){
        int u=(x>>j)&1ll;
        if(tr[now][u^1]&&cnt[tr[now][u^1]]){
            ans+=(1ll<<j);
            now=tr[now][u^1];
        }else{
            now=tr[now][u];
        }
    }
   // std::cerr<<x<<" "<<ans<<'\n';
    return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n,k;
    std::cin>>n>>k;
    std::priority_queue<PII,std::vector<PII>>pq;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    xors[0]=0;
    for(int j=1;j<=n;j++){
        xors[j]=(xors[j-1]^a[j]);
    }
    root[0]=modify(0,0,1);
    for(int j=1;j<=n;j++){
        root[j]=modify(root[j-1],xors[j],1);
        int ans=query(root[j],xors[j]);
       // std::cout<<j<<" "<<ans<<'\n';
        pq.push({ans,j});
        vis[j]=root[j];//version j's idx;
    }
    int cnt=n;
    ll ans=0;
    for(int j=1;j<=k;j++){
        auto v=pq.top();
        pq.pop();
        ans+=v.first;
        uint p=(v.first^xors[v.second]);
        root[++cnt]=modify(vis[v.second],p,-1);
        uint ansp=query(root[cnt],xors[v.second]);
        pq.push({ansp,v.second});
        vis[v.second]=root[cnt];
    }
    std::cout<<ans<<'\n';
	return 0;
}
