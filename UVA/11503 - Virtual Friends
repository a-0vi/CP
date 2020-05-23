#include<bits/stdc++.h>

using namespace std;

map <string, string> par;
map <string, int> peep;

string find_par(string s)
{
    if(par[s] == s) return s;
    return par[s] = find_par(par[s]);
}

void connect(string s1, string s2)
{
    string u = find_par(s1);
    string v = find_par(s2);
    if(u != v){
        par[v] = u;
        peep[u] += peep[v];
    }
}

void solve()
{
   int tt; cin >> tt;
   while(tt--){
       int n; cin >> n;
       while(n--){
           string f1, f2; cin >> f1 >> f2;
           if(!peep[f1]) peep[f1] = 1, par[f1] = f1;
           if(!peep[f2]) peep[f2] = 1, par[f2] = f2;
           connect(f1, f2);
           cout << peep[par[f1]] << "\n";
       }
       peep.clear();
       par.clear();
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
