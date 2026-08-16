#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;
void to(std::string &s){
    for(auto &v:s){
        if(v>='a'&&v<='z'){
            v=v-'a'+'A';   
        }
    }
}
void solve() {
   int n;
   std::cin>>n;
   std::string s;
   std::map<std::string,int>st;
   for(int i=0;i<n;i++){
      std::cin>>s;
      to(s);
      st[s]++;
   }
   int mx=0;
   for(auto [u,cnt]:st){
      mx=std::max(cnt,mx);
   }
   std::cout<<mx<<'\n';
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
