#include <iostream>
using namespace std
  
void solve()
{
    int n, x;
    cin >> n >> x;
    map<int, int> nums;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        nums[t % 2]++;
    }
    for(int i = 1; i < nums[1]; i += 2)
    {
        int need = x - i;
        if( need <= nums[0] && need >= 0 )
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
  
int main(void)
{
    //freopen("input", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
