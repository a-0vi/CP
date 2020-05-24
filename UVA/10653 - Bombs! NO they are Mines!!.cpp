#include<bits/stdc++.h>

#define pii pair<int, int>

int dir4[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

using namespace std;

int row, col;
bool blocked[1001][1001];

void bfs(int sx, int sy, int dx, int dy)
{
    int dis[1001][1001];
    memset(dis, -1, sizeof dis);
    dis[sx][sy] = 0;
    queue<pii > q;
    q.push(pii(sx, sy));

    while(!q.empty()){
        pii u = q.front();
        if(u.first == dx && u.second == dy) break; 
        for(int i = 0; i < 4; i++){
            int cur_x, cur_y;
            cur_x = u.first + dir4[i][0];
            cur_y = u.second + dir4[i][1];
            if(cur_x >= 0 && cur_x < row && cur_y >= 0 && cur_y < col && dis[cur_x][cur_y] == -1 && !blocked[cur_x][cur_y]){
                dis[cur_x][cur_y] = dis[u.first][u.second] + 1;
                q.push(pii(cur_x, cur_y));
            }
        }
        q.pop();
    }
    cout << dis[dx][dy] << "\n";
}

void solve()
{
    while(cin >> row >> col && row && col){

        int rowPos; cin >> rowPos;
        memset(blocked, false, sizeof blocked);
        while(rowPos--){
            int r; cin >> r;
            int colPos;
            cin >> colPos;
            for(int i = 1; i <= colPos; i++){
                int c; cin >> c;
                blocked[r][c] = true;
            }
        }
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        bfs(sx, sy, dx, dy);
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
