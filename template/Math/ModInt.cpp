#include<bits/stdc++.h>
using ll=long long;
const int mod=998244353;
int qpow(int x,int y){
    int r=1;
    while(y){
        if(y&1){
           r=1ll*r*x%mod;  
        }
        x=1ll*x*x%mod;
        y>>=1;
    }
    return r;
}
struct MInt{
    int val;
    static int norm(ll x,int m=mod){
        x%=m;
        if(x<0)x+=m;
        return x;
    }
    MInt():val(0){}
    MInt(ll x):val(norm(x)){}
    MInt pow(ll x){
        return val?qpow(val,norm(x,mod-1)):0;
    }
    MInt inv(){
        return pow(-1);
    }
    
    friend MInt operator+(MInt a,MInt b){return (a.val+b.val);}
    friend MInt operator-(MInt a,MInt b){return (a.val-b.val);}
    friend MInt operator*(MInt a,MInt b){return (1ll*a.val*b.val);}
    friend MInt operator/(MInt a,MInt b){return  a*b.inv();}

    friend MInt& operator+=(MInt &a,MInt b){return a=a+b;}
    friend MInt& operator-=(MInt &a,MInt b){return a=a-b;}
    friend MInt& operator*=(MInt &a,MInt b){return a=a*b;}
    friend MInt& operator/=(MInt &a,MInt b){return a=a/b;}


    friend std::istream& operator>>(std::istream &is,MInt &x){
        ll v;
        is>>v;
        x=MInt(v);
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream &os,MInt x){
        return os<<x.val;
    }
};
using Z=MInt;