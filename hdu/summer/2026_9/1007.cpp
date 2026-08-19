#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int P=1e9+10;
namespace Random{
    mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()  
    );
    template <class T> T randint(T a, T b){
        static_assert(std::is_integral_v<T>&&!std::is_same_v<std::remove_cv_t<T>,bool>);
        assert(a<=b);
        return uniform_int_distribution<T>(a,b)(rng);
    }
};
using namespace Random;
const int N=3e6+10;
int n,q,k;
struct BIT{
    ll b[N];
    void upd(int x,ll k){
        for(;x<=n;x+=(-x&x)){
            b[x]+=k;
        }
        return ;
    }
    ll query(int x){
        ll k=0;
        if(x==0){
            return k;
        }
        for(;x;x-=(-x&x)){
             k+=b[x];        
        }
        return k;
    }
    void clr() {
        for(int i=1;i<=n;i++)b[i] = 0;
    }
}bit;
void solve() {
    std::cin>>n>>q>>k;
    std::vector<int>a(n+1),d(n+1);
    for(int i=1;i<=n;i++)std::cin>>a[i];
    for(int j=1;j<=n;j++)std::cin>>d[j];
    bit.clr();
    std::map<int,int>st;
    std::map<int,ll>sum;
    std::map<PII,bool>vis;
    std::map<PII,ll>mp;
    for(int i=1;i<=n;i++){
        if(!vis[{a[i],d[i]}]){
            if(st[a[i]]==k-1){
                mp[{a[i],d[i]}]=-sum[a[i]];
                st[a[i]]++;
                vis[{a[i],d[i]}]=true;
                continue;
            }
            ll rm=Random::randint(1,P);
            mp[{a[i],d[i]}]=rm;
            vis[{a[i],d[i]}]=true;
            sum[a[i]]+=rm;
            st[a[i]]++;
        }
    }
     for(int i=1;i<=n;i++){
        bit.upd(i,mp[{a[i],d[i]}]);
     }
     while(q--){
        int opt,p,x,c,l,r;
        std::cin>>opt;
        if(opt==1){
            std::cin>>p>>x>>c;
            if(!vis[{x,c}]){
                if(st[x]==k-1){
                    mp[{x,c}]=-sum[x];
                    st[x]++;
                    vis[{x,c}]=true;
                    continue;
                }
                ll rm=Random::randint(1,P);
                mp[{x,c}]=rm;
                vis[{x,c}]=true;
                sum[x]+=rm;
                st[x]++;
            }
            
            bit.upd(p,-mp[{a[p],d[p]}]);
            a[p]=x,d[p]=c;
            bit.upd(p,mp[{a[p],d[p]}]);
        }else{
            std::cin>>l>>r;
            ll sum=bit.query(r)-bit.query(l-1);
            if(sum==0){
                std::cout<<"YES"<<'\n';
            }else{
                std::cout<<"NO"<<'\n';
            }
        }
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
