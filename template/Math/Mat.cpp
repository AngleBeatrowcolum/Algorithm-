#include<bits/stdc++.h>
using ll=long long;
//
struct Mat{
    int v[105][105]={0}
    int x,y;
    Mat(){memset(v,0x3f,sizeof(v));x=y=0;}
    Mat(int _x,int _y){
        x=_x,y=_y;
        memset(v,0x3f,sizeof(v));
    }
    
    void clear(){
        memset(v,0,sizeof(v));
        x=y=0;
    }
    void I(){
        memset(v,0x3f,sizeof(v));
        for(int i=1;i<=x;i++){
            v[i][i]=0;
        }
    }
    void Mmual(Mat a,Mat b){
        x=a.x,y=b.y;
        int c=a.y;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=1;k<=c;k++){
                    v[i][j]=std::min(v[i][j],a.v[i][k]+b.v[k][j]);
                }
            }
        }
    }
    void show(){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                std::cout<<v[i][j]<<" ";
            }
        }
        std::cout<<'\n';
    }
}
Mat operator*(const Mat &x,const Mat &y){
    Mat res;
    res.Mmual(x,y);
    return res;
}
Mat qpow(Mat a,ll y){
    Mat r=a;
    r.I();
    while(y){
        if(y&1)r=r*a;
        b>>=1;
        a=a*a;
    }
    return r;
}
int main(){
    
}