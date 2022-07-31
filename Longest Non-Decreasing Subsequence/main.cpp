#include<bits/stdc++.h>
using namespace std;

#define mxn 1e9
#define pb push_back
#define ull unsigned long long
#define ll long long
#define pop pop_back


void solve()
{
    vector<int> nums = {1,2,4,3};j
    int n = nums.size();

    int dp[n+1];
    memset(dp, 1, sizeof(dp));
    dp[0] = 1;
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        if( nums[i] >= nums[i-1] )
        {
            dp[i] = max(1, dp[i-1] + 1);
        }
        else
        {
            dp[i] = 1;
        }
    }
    
    int mx = -1;
    for(int i = 0; i < n+1; i++)
    {
        if( dp[i] > mx )
        {
            mx = dp[i];
        }
    }

    cout << mx << endl;
    
}
int main(void)
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);

    solve();
    return 0;
}
