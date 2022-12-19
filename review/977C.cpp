#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
    }

    sort(arr.begin(), arr.end());
    int ans;
    if( k == 0 )
        ans = arr[0] - 1;
    else
        ans = arr[k-1];
    int count = 0;
    for(int i = 0; i < n; i++)
        if( arr[i] <= ans )
            count++;
    if( count != k || (ans < 1 || ans > 1e9 ) )
        cout << -1 << endl;
    else 
        cout << ans << endl;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}


