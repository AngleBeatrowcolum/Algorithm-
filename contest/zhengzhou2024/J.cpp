#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
std::vector<int>minp,primes;
void seive(int n){
    minp.assign(n+1,0);
    primes.clear();
    
    for(int i=2;i<=n;i++){
        if(minp[i]==0){
            minp[i]=i;
            primes.emplace_back(i);
        }
        for(auto p:primes){
            if(i*p>n)break;
            minp[i*p]=p;
            if(p==minp[i]){
                break;
            }
        }
    }
}
bool isprime(int n){
    return minp[n]==n;
}
void solve() {
    int n;
    std::cin>>n;
    std::array<int,5>cnt;
    int pos=0;
    while(n){
        cnt[pos]=n%10;
        n/=10;
        pos++;
    }
    std::vector<int>vec;
    std::array<bool,10>vis;
    vis.fill(false);
    bool flag=false;
    auto dfs=[&](auto &&self,int step)->void{
        if(flag){
            return ;
        }
        if(step==5){
            int p=10000;
            int ans=0;
            for(auto v:vec){
                ans+=p*v;
                p/=10;
            }
            if(!isprime(ans)){
                flag=true;
                return ;
            }
            return;
        }
        for(int i=0;i<5;i++){
            if((step==0&&cnt[i]==0)||vis[cnt[i]]){
                continue;
            }else{
                vis[cnt[i]]=true;
                vec.emplace_back(cnt[i]);
                self(self,step+1);
                if(flag){
                    return ;
                }
                vis[cnt[i]]=false;
                vec.pop_back();
            }
        }
        
    };
    dfs(dfs,0);
    if(flag){
        for(auto v:vec){
            std::cout<<v;
        }
        std::cout<<'\n';
    }else{
        std::cout<<-1<<'\n';
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    seive(1e5);
    int T = 1;
     cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
