#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    std::cin>>n;
    
    std::vector<ll>a(n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    
    for(int i=1;i<n;i++){
        a[i+1]+=a[i]-i;
        if(a[i]-i<=0)continue;
        a[i]=i;
    }
    
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i-1]){
            std::cout<<"No"<<'\n';
            return ;
        }
    }
    std::cout<<"Yes"<<'\n';
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
