#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
const int N=3e5+10;
const int MAXN=1e9;
int a[N];
void solve() {
    int n;
    std::cin>>n;
    std::priority_queue<int,std::vector<int>,std::greater<int>>pq;
    std::priority_queue<int,std::vector<int>>st;
    int mn,mx;
    mn=N,mx=-N;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(a[i]<0){
            mx=std::max(mx,a[i]);
            st.push(a[i]);
        }else{
            mn=std::min(mn,a[i]);
            pq.push(a[i]);
        }
    }
    int flag;
    if(abs(mx)<=mn){
        flag=-1;
       // st.pop();
    }else{
        flag=1;
        //pq.pop();
    }
    int pos=0;
    ll ans=0;
   // std::cerr<<flag<<'\n';
    while(!pq.empty()||!st.empty()){
      //  std::cerr<<pos<<'\n';
        if(flag==-1){
            int u=st.top();
            st.pop();
            ans+=abs(pos-u);
            pos=u;
        }else{
            int u=pq.top();
            pq.pop();
            ans+=abs(pos-u);
            pos=u;
        }
        if(pq.empty()&&st.empty()){
            break;
        }else if(pq.empty()){
            flag=-1;
        }else if(st.empty()){
            flag=1;
        }else{
            int u=st.top();
            int v=pq.top();
            if(abs(u-pos)>abs(v-pos)){
                flag=1;
            }else{
                flag=-1;
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
