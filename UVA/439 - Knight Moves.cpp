#include<bits/stdc++.h>

#define pii pair<int, int>

int knight[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};

using namespace std;


int bfs(int sx, int sy, int dx, int dy)
{
    int dis[9][9]; memset(dis, -1, sizeof dis);
    dis[sx][sy] = 0;
    queue<pii > q;
    q.push(pii(sx,sy));
    while(!q.empty()){
        pii u = q.front(); q.pop();
        if(u.first == dx && u.second == dy) break;
        for(int i = 0 ; i < 8; i++){
            int vx = u.first + knight[i][0];
            int vy = u.second + knight[i][1];
            if(vx >= 1 && vx <= 8 && vy >= 1 && vy <= 8 && dis[vx][vy] == -1){
                dis[vx][vy] = dis[u.first][u.second] + 1;
                q.push(pii(vx, vy));
            }
        }
    }
    return dis[dx][dy];

}

void solve()
{
    string from, to;
    while(cin >> from >> to){
        int sx, sy, dx,dy;
        sx = from[1] - '0'; sy = from[0] - 'a' + 1;
        dx = to[1] - '0'; dy = to[0] - 'a' + 1;
        int ans = bfs(sx, sy, dx, dy);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", from[0], from[1], to[0], to[1], ans);
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
