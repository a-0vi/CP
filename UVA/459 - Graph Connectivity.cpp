#include<bits/stdc++.h>

using namespace std;

map <char, char> par;

char rep(char c)
{
    if(par[c] == c) return c;
    return par[c] = rep(par[c]);
}

void disjoint(char a, char b)
{
    par[rep(a)] = rep(b);
}

void solve()
{
    int n; cin >> n;
    bool flag = false;
    while(n--){
        if(flag) cout << "\n";
        flag = true;
        string s; cin >> s;
        string edge;
        char mx = s[0];
        for(char idx = 'A'; idx <= mx; idx++) par[idx] = idx ;
        cin.ignore();
        while(getline(cin, edge) && edge != "" ){
            char a, b;
            a = edge[0]; b = edge[1];
            if(rep(a) != rep(b) ) disjoint(a, b);
            // cout << edge << "\n";
        }
        int ans = 0;
        for(char i = 'A'; i <= mx; i++) if(par[i] == i) ans++;
        cout << ans << "\n";
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
