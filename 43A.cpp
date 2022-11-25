#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    map<string, int> g;
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        g[t]++;
    }
    int mx = -1;
    string ans;
    for(auto it = g.begin(); it != g.end(); ++it)
    {
        if( it->second > mx ) 
        {
            ans = it->first;
            mx = it->second;
        }
    }

    cout << ans << endl;

}


int main(void)
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}


