#include<bits/stdc++.h>

using namespace std;

map<string, vector<string> > edges;
map<string, string> parent;

// void printRoute(string s, string d)
// {
//     if(d == s) return;
//     printRoute(s, parent[d]);
//     cout << parent[d] << " " << d << "\n";
// }

void bfs(string s, string d)
{
    parent[s] = s;
    queue<string>q;
    q.push(s);
    while(!q.empty()){
        string u = q.front(); q.pop();
        if(u == d) break;
        if(edges.count(u) == 0) break;
        for(int i = 0; i < edges[u].size(); i++){
            string v = edges[u][i];
            if(parent[v] == "-1"){
                parent[v] = u;
                q.push(v);
                
            }
        }
    }
    
    if(edges.count(d) == 0 || parent[d] == "-1") cout << "No route\n";
//     else printRoute(s, d);
    else {
        vector<string> ans;
        ans.push_back(d);
        while(parent[d] != d){
            ans.push_back(parent[d]);
            d = parent[d];
        }
        for(int i = ans.size() - 1; i > 0; i--) cout << ans[i] << " " << ans[i-1] << "\n";
    }

}

void solve()
{
    int edgeNum;
    bool newLine = false;
    while(cin >> edgeNum){
        if(newLine) cout << "\n";
        newLine = true;
        string start, destination;
        for(int i = 1; i <= edgeNum; i++){
            cin >> start >> destination;
            edges[start].push_back(destination);
            edges[destination].push_back(start);
            parent[start] = "-1";
            parent[destination] = "-1";

        }
        cin >> start >> destination;
        bfs(start, destination);
        // cout << edges["KA"].size();
        edges.clear();
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
