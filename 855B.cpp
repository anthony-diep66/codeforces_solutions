#include<bits/stdc++.h>
using namespace std;
#define INF 0xf7
#define mxn 1e9
#define pb push_back
#define ull unsigned long long
#define ll long long 
#define pop pop_back


void solve()
{
    // state: maximum value of a term + terms before it, so max of (p*ai), (p * ai + q*aj), (p * ai + q*aj + r*ak)
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a = {p,q,r};
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    
    ll dp[n][3];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[i][j] = -1;
        }
    }

    //base cases: p, q, r * 0th number
    dp[0][0] = (ll) a[0] * arr[0];
    dp[0][1] = (ll) a[1] * arr[0];
    dp[0][2] = (ll) a[2] * arr[0];
    
    dp[0][1] += dp[0][0];
    dp[0][2] += dp[0][1];
    
    for(int i = 1; i < n; i++) // find max for p term
    {
        dp[i][0] = max(dp[i-1][0], (ll) a[0] * arr[i]);
    }
    for(int i = 1; i < n; i++) // find max for q term + corresponding p terms since p*a_i + q*a_j
    {
        dp[i][1] = max(dp[i-1][1], (ll) a[1] * arr[i] + dp[i][0]);
    }
    for(int i = 1; i < n; i++) // find max for r term, ^^^
    {
        dp[i][2] = max(dp[i-1][2], (ll) a[2] * arr[i] + dp[i][1]);
    }
    cout << dp[n-1][2] << endl;

}


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}


