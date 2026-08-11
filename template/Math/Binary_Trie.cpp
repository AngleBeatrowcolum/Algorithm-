#include<bits/stdc++.h>
const int MAXN=4e6;

//do for int 
struct Trie{
	//every time I insert a number , the upper_bound is it' binary number;
    int son[MAXN][2];
	int idx;
	void add(int x){
		int p=0;
		for(int i=30;i>=0;i--){
			int u=(x>>i)&1;
			if(!son[p][u]){
				son[p][u]=++idx;
			}
			p=son[p][u];
		}
	}
	int query(int x){
	    int p=0,res=0;
		for(int i=30;i>=0;i--){
			int u=(x>>i)&1;
			if(son[p][u^1]){
				res|=(1<<i);
			}else{
				p=son[p][u];
			}
		}
		return res;      	
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	

	return 0;
}
