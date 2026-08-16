#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
     int Q,V;
     std::cin>>Q>>V;
     std::priority_queue<ll,std::vector<ll>>pq;
     while(Q--){
        int opt,t;
        std::cin>>opt>>t;
        if(opt==1){
            int w;
            std::cin>>w;
            pq.push(w-t);
        }else{
            if(pq.empty()){
               std::cout<<-1<<'\n'; 
            }else{
                int u=pq.top();
                pq.pop();
                if(u+t>V){
                    std::cout<<V<<'\n';
                }else{
                    std::cout<<u+t<<'\n';
                }
            }
        }
     }
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
