#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII=std::pair<int,int>;
using ull=unsigned long long;
const int N=2e5+10;
int h[N],d[N];
PII b[N],c[N];
bool cmp(const PII &a,const PII &b){
    return a.first<b.first;
}
bool cmp1(const PII &a,const PII &b){
    return a.first>b.first;
}
int cnt=0,cnts=0;
const ull R=9e18;
bool check(ull mid){
    for(int i=1;i<=cnt;i++){
        if(mid>=b[i].first){
            mid+=b[i].second;
        }else{
            return false;
        }
    }
    for(int j=1;j<=cnts;j++){
        if(mid>=c[j].first){
            mid+=c[j].second;
        }else{
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>h[i]>>d[i];
        if(d[i]>=0){
            b[++cnt]={h[i],d[i]};
        }else{
            c[++cnts]={h[i],d[i]};
        }
    }
    ull l=0,r=R;
    
    std::sort(b+1,b+1+cnt,cmp);
    std::sort(c+1,c+1+cnts,cmp1);
    ull ans=0;
    while(l<=r){
        ull mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=r;
        }else{
            l=mid+1;
        }
    }
    std::cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
