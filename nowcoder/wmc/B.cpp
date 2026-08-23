#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
    int n,m,x,y,k;
    std::cin>>n>>m>>x>>y>>k;
    int minx=1e5;
    for(int i=0;i<=k;i++){
        int p=std::min(n,3*i);
        int mix=i*2*x+(n-p)*x;
        int q=std::min(k-i,m/4);
        int mpx=q*3*y+(m-q*4)*y;
        minx=std::min(minx,mix+mpx);
        
    }
    std::cout<<minx<<'\n';
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
