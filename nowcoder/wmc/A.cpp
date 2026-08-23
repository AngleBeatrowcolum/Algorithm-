#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
    int xc,yc,zc;
    std::cin>>xc>>yc>>zc;
    std::cout<<xc-1<<" "<<yc-1<<" "<<zc-1<<" ";
    std::cout<<xc+1<<" "<<yc+1<<" "<<zc+1;
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
