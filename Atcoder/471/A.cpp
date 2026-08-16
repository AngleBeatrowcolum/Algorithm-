#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull = unsigned long long;
using uint = unsigned int;

void solve() {
  int a,b;
  std::cin>>a>>b;
  if(a+b==9||a-b==9||a*b==9||(a/b==9&&a%b==0)){
     std::cout<<"Nine"<<'\n';
  }else{
      std::cout<<"Nein"<<'\n';
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
