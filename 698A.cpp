#include<bits/stdc++.h>
using namespace std;
#define mxn 1e9


void solve()
{
    // state = minimum number of days rested if i_th activity is chosen
    // where i = 0 -> rest, i = 1 -> contest, i = 2 -> sport
    // trandition: dp[day][i] = min( dp[day-1][0], dp[day-1][1], dp[day-1][2] )
    // - a rest can be done for any day
 
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    
    //  dp[activity][day]
    int dp[3][n];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = mxn;
        }
    }

    //base cases: see how many rest days if i_th activity is taken on the 0th day
    dp[0][0] = 1;
    if( arr[0] == 1 || arr[0] == 3 ) dp[1][0] = 0;
    if( arr[0] == 2 || arr[0] == 3 ) dp[2][0] = 0;

    //dp starts
    //take the minimum rest days from the previous day if the i_th activity was done that day
    for(int day = 1; day < n; day++)
    {
        dp[0][day] = min(dp[0][day-1], min(dp[1][day-1], dp[2][day-1])) + 1;
        if( arr[day] == 1 || arr[day] == 3 )
        {
            dp[1][day] = min(dp[0][day-1], dp[2][day-1]);
        }
        if( arr[day] == 2 || arr[day] == 3 )
        {
            dp[2][day] = min(dp[0][day-1], dp[1][day-1]);
        }
    }
    cout << min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]));

}

int main(void)
{
    solve();
    return 0;
}
