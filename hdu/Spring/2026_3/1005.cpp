#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
ll mask1[40];
int d[40][40];
void init(){
    memset(mask1,0,sizeof(mask1));
    memset(d,0,sizeof(d));
}
ll cnt[39];
void init1(){
    cnt[0]=1;
    for(int i=1;i<=38;i++){
        cnt[i]=cnt[i-1]*3ll;
    }
}
int ds[3]={0,1,2};
ll cal(ll x,int i,int rks){
    int p=d[i][i];
   // if(x==7)std::cout<<p<<" ";
    int pos=0;
    ll ans=0;
    while(x){
        //I need x max
        int ms=x%3;
        ms=(ms-rks*d[i][pos]+9)%3;
        ans+=ms*cnt[pos];
        x/=3;
        pos++;
    }
    return ans;
}
void insert(ll x,int pk){
     for(int i=38;i>=0;i--){
        ll rm=x;
        int pos=0;
        while(pos!=i){
            pos++;
            rm/=3;
           // std::cout<<rm<<" "<<pk<<" "<<pos<<'\n';
        }
    //    std::cerr<<rm<<" "<<pk<<" "<<x<<'\n';
        int ps=rm%3;
        if(ps){
           // std::cout<<pk<<" "<<ps<<'\n';
            if(!mask1[i]){
                ll rk=x;
                int pos=0;
                ll t=0;
                while(rk){
                    d[i][pos]=((rk%3)*ds[ps])%3;
                    rk/=3;
                    t+=1ll*d[i][pos]*cnt[pos];
                    pos++;
                }
             //   t+=1llcnt[pos];
                mask1[i]=t;
                break;
            }else{
               x=cal(x,i,ps);
            }
        }
     }
}
bool pd(ll x){
    for(int i=38;i>=0;i--){
        ll rm=x;
        int pos=0;
        while(pos!=i){
            pos++;
            rm/=3;
        }
        int ps=rm%3;

        if(ps){
           
            if(mask1[i]){
               x=cal(x,i,ps);
            }else{
                return false;
            }
            
        }
    }
    return true;
}
void solve() {
     int n,q;
     std::cin>>n>>q;
     std::vector<ll>v(n+1);
     init();
     for(int i=1;i<=n;i++){
        std::cin>>v[i];
      //  std::cerr<<v[i]<<'\n';
        insert(v[i],i);
     }

     while(q--){
        ll s;
        std::cin>>s;
        bool m=pd(s);
        
        if(m){
            std::cout<<"Yes"<<'\n';
        }else{
            std::cout<<"No"<<'\n';
        }
     }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init1();
    int T = 1;
     cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
