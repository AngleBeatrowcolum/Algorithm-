#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
    int n;
    std::cin>>n;
    int ans=0;
    std::string s;
    for(int i=1;i<=n;i++){
        std::cin>>s;
        if(s.length()!=5)continue;
        bool flag=true;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                if(s[i]==s[j])flag=false;
            }
        }
        if(s[2]!=s[4])flag=false;
        if(flag)ans++;
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
