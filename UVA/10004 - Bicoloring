#include<bits/stdc++.h>

using namespace std;

void bfs(int E)
{
    vector<int> nodes[201];
    int dis[201];
    memset(dis, -1, sizeof dis);
    for(int i = 1; i <= E; i++){
        int x, y; cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < nodes[u].size(); i++){
            int v = nodes[u][i];
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
            else{
                if(dis[v] == dis[u]) {
                    cout << "NOT BICOLORABLE.\n";
                    return;
                }
            }
        }
    }
    cout <<"BICOLORABLE.\n";
    return;
}

void solve()
{
    int nodeNum;
    while(cin >> nodeNum && nodeNum){
        int edgeNum; cin >> edgeNum;
        bfs(edgeNum);
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
