#include<bits/stdc++.h>

using namespace std;

int kase = 1;

int bfs(vector<int> g[21], int s, int d)
{
    int dis[21];
    memset(dis, -1, sizeof dis);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        if(u == d) break;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        q.pop();
    }
    return dis[d];
}

void solve()
{
    int first;
    while(cin >> first){
        vector<int>g[21];
        for(int i = 0; i < first; i++){
            int x; cin >> x;
            g[1].push_back(x);
            g[x].push_back(1);
        }
        for(int i = 2; i < 20; i++){
            int edge;cin >> edge;
            while(edge--){
                int x; cin >> x;
                g[i].push_back(x);
                g[x].push_back(i);
            }
        }
        int n; cin >> n;
        printf("Test Set #%d\n", kase++);
        for(int i = 1; i <= n; i++){
            int start, destination;
            cin >> start >> destination;
            printf("%2d to %2d: %d\n", start, destination, bfs(g, start, destination));
        }
        cout << "\n";
    }
}
//new line is printed in the main

int main()
{
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
