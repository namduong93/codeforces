#include<bits/stdc++.h>
#define fto(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
set<int> G[200005];
 
void dfs(set<int>& st,int curr){
	if(st.find(curr)!=st.end()){
		return ;
	}
	st.insert(curr);
	for(auto i:G[curr]){
		dfs(st,i);
	}
}
 
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,c1,c2;
		cin>>n>>m>>c1>>c2;
 
		fto(i,1,n)
			G[i].clear();
 
		fto(i,0,m-1){
			int f,t;
			cin>>f>>t;
			G[f].insert(t);
			G[t].insert(f);
		}
 
		for(auto i:G[c1]){
			G[i].erase(c1);
		}
		set<int> st1;
		dfs(st1,c2);
 
		for(auto i:G[c1]){
			G[i].insert(c1);
		}
 
		for(auto i:G[c2]){
			G[i].erase(c2);
		}
		set<int> st2;
		dfs(st2,c1);
 
		cout<<1ll * (n-st1.size()-1) *(n-st2.size()-1) <<endl;
 
	}
	return 0;
}