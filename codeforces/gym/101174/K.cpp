/**
 *    author:  AMO5
 *    created: 07.10.2022 14:19:02 
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O2") // Apple, please fix XCode 14.0

using namespace std;

#define i64 long long
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define dbg if(0)

const int mxn = (int)2e5+5;
i64 getId(int a, int b, int c){
    return 1ll * a * 300000000 + 1ll * b * 20000 + c;
}

void solve(){
    int n; cin >> n;
    
    vector<pair<i64,i64>>id3d, id2d;

    vector<i64>id3ds, id2ds;

    for(int i=0; i<n; i++){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        i64 id = getId(a, b, c), id2 = getId(d, e, f);
        i64 id3 = getId(a, b, 0), id4 = getId(d, e, 0);

        id3d.emplace_back(id, id2);
        id2d.emplace_back(id3, id4);

        id3ds.push_back(id);
        id3ds.push_back(id2);
        id2ds.push_back(id3);
        id2ds.push_back(id4);
    }
	
    sort(all(id3ds));
    id3ds.erase(unique(all(id3ds)), id3ds.end());

    sort(all(id2ds));
    id2ds.erase(unique(all(id2ds)), id2ds.end());

    int m3 = sz(id3ds), m2 = sz(id2ds);
    vector<vector<i64>>adj3(m3), adj2(m2);

    for(int i=0; i<n; i++){
        {
            i64 id = id3d[i].first;
            i64 id2 = id3d[i].second;

            id = lower_bound(all(id3ds), id) - id3ds.begin();
            id2 = lower_bound(all(id3ds), id2) - id3ds.begin();

            if(id != id2){
                adj3[id].push_back(id2);
                adj3[id2].push_back(id);
            }
        }
        {
            i64 id = id2d[i].first;
            i64 id2 = id2d[i].second;

            id = lower_bound(all(id2ds), id) - id2ds.begin();
            id2 = lower_bound(all(id2ds), id2) - id2ds.begin();


            if(id != id2){
                adj2[id].push_back(id2);
                adj2[id2].push_back(id);
            }
        }
    }

    for(int i=0; i<m3; i++){
        sort(all(adj3[i]));
        adj3[i].erase(unique(all(adj3[i])), adj3[i].end());
    }

    for(int i=0; i<m2; i++){
        sort(all(adj2[i]));
        adj2[i].erase(unique(all(adj2[i])), adj2[i].end());
    }

    {
        bool cycle = false;
        vector<int>vis(m3, 0);
        auto dfs = [&](auto &&dfs, int u, int p)->void{
            if(cycle == true)return;
            vis[u] = 2;
            for(i64 &v:adj3[u]){
                if(v == p || v == u)continue;
                if(vis[v] == 2){
                    cycle = true;
                    return;
                }
                if(vis[v] == 0)
                    dfs(dfs, v, u);
            }
            vis[u] = 1;
        };

        dfs(dfs, 0, 0);
        
        cout << (cycle ? "True closed chains" : "No true closed chains") << '\n';
    }

    {
        bool cycle = false;
        vector<int>vis(m2, 0);
        auto dfs = [&](auto &&dfs, int u, int p)->void{
            if(cycle == true)return;
            vis[u] = 2;
            for(i64 &v:adj2[u]){
                if(v == p || v == u)continue;
                if(vis[v] == 2){
                    cycle = true;
                    return;
                }
                if(vis[v] == 0)
                    dfs(dfs, v, u);
            }
            vis[u] = 1;
        };

        dfs(dfs, 0, 0);
        
        cout << (cycle ? "Floor closed chains" : "No floor closed chains") << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}