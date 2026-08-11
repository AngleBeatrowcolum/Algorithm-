#include<bits/stdc++.h>
struct Segt{
    struct node{
        std::array<int,10>w,cnt;
        friend node operator+(const node &a,const node&b){
            node c;
            for(int j=0;j<10;j++){
                c.cnt[j]=a.cnt[j]+b.cnt[j];
                if(c.cnt[j]==0)c.w[j]=0;
                else c.w[j]=1;
            }
            return c;
        }
    };
    std::vector<int>w;
    std::vector<node>t;
    Segt(){}
   
    void init(std::vector<int>in){
        int n=in.size()-1;
        w.resize(n+1);
        for(int i=1;i<=n;i++){
            w[i]=in[i];
        }
        t.resize(n*4+1);
        auto build=[&](auto &&self,int l,int r,int p=1){
            if(l==r){
                for(int j=0;j<10;j++){
                    t[p].w[j]=(w[l]>>j&1)==0?0:1;
                    t[p].cnt[j]=(w[l]>>j&1)==0?0:1;
                }
                return ;
            }
            int mid=(l+r)>>1;
            self(self,l,mid,p<<1);
            self(self,mid+1,r,p<<1|1);
            t[p]=t[p<<1]+t[p<<1|1];
        };
        build(build,1,n);
    }
    void modify(int p,int l,int r,int pos,int k){
        if(l>pos||r<pos){
            return;
        }
        if(l==r){
            for(int j=0;j<10;j++){
                 t[p].w[j]=(k>>j&1)==0?0:1;
                 t[p].cnt[j]=(k>>j&1)==0?0:1;
            }
            return ;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)modify(p<<1,l,mid,pos,k);
        else modify(p<<1|1,mid+1,r,pos,k);
        t[p]=t[p<<1]+t[p<<1|1];
    }
    void update(int p,int l,int r,int pos,int k){
        if(l>pos||r<pos){
            return ;
        }
        if(l==r){
            t[p].w[k]=1;
            t[p].cnt[k]=1;
            return ;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)update(p<<1,l,mid,pos,k);
        else update(p<<1|1,mid+1,r,pos,k);
        t[p]=t[p<<1]+t[p<<1|1];
    }
    int ask(int p,int l,int r,int ql,int qr,int x){//find the left 
        if(qr<l||ql>r||t[p].cnt[x]==r-l+1){
            return 0;
        }
        if(l==r){
            return l;
        }
        int mid=(l+r)>>1;
        int res=ask(p<<1,l,mid,ql,qr,x);
        if(res)return res;
        return ask(p<<1|1,mid+1,r,ql,qr,x);
    }
    int ask1(int p,int l,int r,int ql,int qr,int x){//find the right;
        if(qr<l||ql>r||t[p].cnt[x]==r-l+1){
            return 0;
        }
        if(l==r){
            return l;
        }
        int mid=(l+r)>>1;
        int res=ask1(p<<1|1,mid+1,r,ql,qr,x);
        if(res)return res;
        return ask1(p<<1,l,mid,ql,qr,x);
    }
};
struct HLD{
    int n,idx;
    std::vector<std::vector<int>>adj;
    std::vector<int>siz,dep;
    std::vector<int>top,son,parent;
    std::vector<int>dfn,rnk,in,val;
    Segt segt;
    HLD(int n){
        this->n=n;
        adj.resize(n+1);
        siz.resize(n+1);
        dep.resize(n+1);
        
        top.resize(n+1);
        son.resize(n+1);
        parent.resize(n+1);
        
        idx=0;
        in.resize(n+1);
        dfn.resize(n+1);
        rnk.resize(n+1);
        val.resize(n+1);
    }
    void add(int x,int y){
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    void dfs1(int u){
        siz[u]=1;
        dep[u]=dep[parent[u]]+1;
        for(auto v:adj[u]){
            if(v==parent[u])continue;
            parent[v]=u;
            dfs1(v);
            siz[u]+=siz[v];
            if(!son[u]||siz[son[u]]<siz[v]){
                son[u]=v;
            }
            
        }
    }
    void dfs2(int u,int up){
        dfn[u]=++idx;
        val[idx]=in[u];
        rnk[idx]=u;//also need a array to query where idx to
        top[u]=up;
      
      //  std::cerr<<top[u]<<" "<<up<<'\n';
        if(son[u])dfs2(son[u],up);
        for(auto v:adj[u]){
            if(v==parent[u]||v==son[u])continue;
            dfs2(v,v);
        }
    }
    void modify(int pos,int k,int index=1){
       // std::cerr<<rnk[dfn[pos]]<<'\n';
        segt.modify(1,1,n,dfn[pos],k);
    }
    void update(int pos,int x,int index=1){
        segt.update(1,1,n,dfn[pos],x);
    }
    
    int findPath(int u,int v,int x){
        std::vector<std::pair<int,int>>segl,segr;
       // std::cerr<<u<<" "<<v<<" "<<top[u]<<" "<<top[v]<<'\n';
        while(top[u]!=top[v]){
         //   std::cerr<<u<<" "<<v<<'\n';
            if(dep[top[u]]>=dep[top[v]]){
                segl.emplace_back(dfn[top[u]],dfn[u]);
                u=parent[top[u]];
            }else{
                segr.emplace_back(dfn[top[v]],dfn[v]);
                v=parent[top[v]];
            }
        }
        if(dep[u]>=dep[v]){
            segl.emplace_back(dfn[v],dfn[u]);
        }else{
            segr.emplace_back(dfn[u],dfn[v]);
        }
        for(auto [l,r]:segl){
            int pos=segt.ask1(1,1,n,l,r,x);
            if(pos) return rnk[pos];
        }
        std::reverse(segr.begin(),segr.end());
        for(auto [l,r]:segr){
            int pos=segt.ask(1,1,n,l,r,x);
            if(pos)return rnk[pos];
        }

        return 0;
    }
    void work(auto in,int root=1){
        this->in=in;
        dfs1(root);
        dfs2(root,root);
        segt.init(val);
    }
};
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    std::cin>>n>>m;
    HLD p(n+1);
    std::vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
   
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        p.add(u,v);
    }
    p.work(a);
    while(m--){
        int opt;
        std::cin>>opt;
        int x,z;
        if(opt==1){
            std::cin>>x>>z;
            p.modify(x,z);
        }else{
            int x,y,z;
            std::cin>>x>>y>>z;
            int ans=0;
            for(int j=0;j<10;j++){
                if((z>>j&1)==1){
                    int p1=p.findPath(x,y,j);
                    if(p1==0){
                        ans+=(1<<j);
                    }else{
                        p.update(p1,j);
                    }
                }
            }
            std::cout<<ans<<'\n';
        }
    }

    return 0;
}