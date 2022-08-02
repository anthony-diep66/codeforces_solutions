#include<bits/stdc++.h>
using namespace std;


void lcs()
{
    // state: length of longest common subsequence at index i of string a and
    //                                                 index j of string b
    // transition: if character matches, move both pointers backwards by 1 and 
    //                add 1 to the overall value (length), else, dp[i][j] is the 
    //                 max of dp[i-1][j] and dp[i][j-1] (no 1 added)
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    int dp[n+1][m+1];
    dp[0][0] = 0;
    
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            if( i == 0 || j == 0 )
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = -1;
            }
        }
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if( a[i-1] == b[j-1] )
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][m];
}


int main(void)
{
    lcs();

    return 0;
}
