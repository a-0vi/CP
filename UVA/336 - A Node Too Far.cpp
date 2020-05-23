#include<bits/stdc++.h>

using namespace std;

int kase = 1;

void bfs(map<int, vector<int> > &g, int start, int ttl)
{
    int ans = 1;
    map<int, int> dis;
    dis[start] = 0;
    
    queue<int> q;
    q.push(start);
    
    if(g.count(start) == 0) ans--;
    while(!q.empty() && dis[q.front()] < ttl){
        int u = q.front(); q.pop();
        if(g.count(u) == 0) break;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!dis.count(v)){
                dis[v] = dis[u] + 1;
                ans++;
                q.push(v);
            }
        }
    }
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
            kase++, g.size() - ans , start, ttl);
}

void solve()
{
    int edgeNum;
    while(cin >> edgeNum && edgeNum){
        map<int, vector<int> > g;
        for(int i = 1; i <= edgeNum; i++){
            int x, y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int start, ttl;
        while(cin >> start >> ttl && (ttl || start)) bfs(g, start, ttl);
    }
}
//new line is printed in the main

int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0); 

    int t = 1;
        //cin >> t; // comment out if no test case is required
    int i = 1;
    while(t--){
        //cout << "Case " << i++ << ": ";
        solve();
        // cout << "\n";
    }
    return 0; 
}
