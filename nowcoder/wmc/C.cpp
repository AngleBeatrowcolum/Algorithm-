#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
ll cal(ll x,ll y,ll x1,ll y1){
    return abs(x-x1)+abs(y-y1);
}
void solve() {
     int n;
     ll x1,y1,x2,y2;
     std::cin>>n>>x1>>y1>>x2>>y2;
     bool flag=true,vis=true;
     if(x1<x2){
        flag=false;
     }  
     if(y1>y2){
        vis=false;
     }
     char c;
     std::vector<char>opt;
     for(int i=1;i<=n;i++){
        std::cin>>c;
        if(c=='L'){
            if(flag){
                opt.emplace_back('B');
                x2--;
            }else{
                opt.emplace_back('A');
                x1--;
            }
        }
        if(c=='R'){
            if(flag){
                opt.emplace_back('A');
                x1++;
            }else{
                opt.emplace_back('B');
                x2++;
            }
        }
         if(c=='U'){
            if(vis){
                y2++;
                opt.emplace_back('B');
            }else{
                y1++;
                opt.emplace_back('A');
            }
        }
         if(c=='D'){
            if(vis){
                y1--;
                opt.emplace_back('A');
            }else{
                y2--;
                opt.emplace_back('B');
            }
        }
     }
     std:cout<<cal(x1,y1,x2,y2)<<'\n';
     for(auto v:opt){
        std::cout<<v;
     }
     std::cout<<'\n';
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
