#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII=std::pair<ll,ll>;
using ull = unsigned long long;
using uint = unsigned int;
bool cmp(const PII &a,const PII &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
void solve() {
     int n;
     std::cin>>n;
     std::vector<int>a(n+1),b(n+1);
     
     for(int i=1;i<=n;i++){
        std::cin>>a[i];
     }
     for(int i=1;i<=n;i++){
        std::cin>>b[i];
     }
     auto check=[&](int mid)->bool{
        std::vector<PII>cnt;
        for(int i=1;i<=n;i++){
            cnt.push_back({1ll*a[i]-1ll*mid*b[i],1ll*a[i]+1ll*mid*b[i]});
        }
        std::sort(cnt.begin(),cnt.end(),cmp);
        for(int i=0;i<cnt.size();i++){
            if(cnt[i].second<cnt[cnt.size()-1].first){
                return false;
            }
        }
        return true;
     };
     int l=0,r=1e9;
     int ans;
     while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
     }
     std::cout<<ans<<'\n';
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
