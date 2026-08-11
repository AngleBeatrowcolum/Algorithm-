#include<bits/stdc++.h>
//Point update,range query
template<typename T>
struct Segt{
    struct node{
       T sum;
       friend node operator+(const node &a,const node &b){
            node c;
            c.sum=a.sum+b.sum;
            return c;
       }
    };
    int n;
    std::vector<node>t;
    std::vector<T>w;
    Segt(std::vector<T>in){
        n=in.size()-1;
        t.resize(n*4+1);
        for(int i=1;i<=n;i++){
            w[i]=in[i];
        }
        auto build=[&](int p,int l,int r)->void{
            if(l==r){
                t[p]={w[l]};
                return ;
            }
            
            int mid=(l+r)/2;
            self(p<<1,l,mid);
            self(p<<1|1,mid+1,r);
            t[p]=t[p<<1]+t[p<<1|1];
        };
        build(1,1,n);
    }
    
    void update(int p,int l,int r,int pos,T k){
        if(l>pos||r<pos)return;
        if(l==r){
            t[p]={k};
            return ;
        }
        
        int mid=(l+r)/2;
        if(pos<=mid)update(p<<1,l,mid,pos,k);
        else update(p<<1|1,mid+1,r,k);
        t[p]=t[p<<1]+t[p<<1|1];
    }
    T query(int p,int l,int r,int ql,int qr){
        if(l>=ql&&r<=qr){
            return t[p].sum;
        }
        if(l>qr||r<ql){
            return 0;
        }
        int mid=(l+r)/2;
        T ans=0;
        if(ql<=mid)ans+=query(p<<1,l,mid,ql,qr);
        if(qr>=mid)ans+=query(p<<1|1,mid+1,r,ql,qr);
        return ans;
    }
};
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);


    return 0;
}