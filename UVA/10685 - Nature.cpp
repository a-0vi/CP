#include<bits/stdc++.h>

using namespace std;

map <string, string> par;
map <string, int> chain;

string rep(string child)
{
    if(par[child] == child) return child;
    return par[child] = rep(par[child]);
}
void disjoint(string creature, string predator)
{
    chain[rep(creature)] += chain[rep(predator)];
    par[rep(predator)] = rep(creature);
}

void solve()
{
   int r, c; 
   while(cin >> r >> c && (r || c)){
       for(int i = 1; i <= r; i++){
           string s; cin >> s;
           chain[s] = 1;
           par[s] = s;
       }
       for(int i = 1; i <= c; i++){
           string x, y;
           cin >> x >> y;
           if(rep(x) != rep(y)) disjoint(x, y);
       }
       int mx = -1;
       for(auto i = chain.begin(); i != chain.end(); i++) mx = max(mx, i->second);
       cout << mx << "\n";
       par.clear();
       chain.clear();
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
