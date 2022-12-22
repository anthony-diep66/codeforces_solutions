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

//in a sorted array "arr", the elements are arranged such that: a_1 <= a_2 <= ... <= a_n.
//if this is the case, then the maximum absolute difference found between any two elements are |a_1 - a_n| (the first and last elements).
//the smallest will be the middle elements.

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0, t; i < n; i++)
    {
        cin >> t;
        arr[i] = t;
    }
    sort(arr.begin(), arr.end());
    if( n % 2 != 0 )
    {
        cout << arr[n/2] << " ";
        for(int i = (n -1) / 2 - 1; i >= 0; i--)
        {
            cout << arr[i] << " " << arr[n - 1- i] << " \n"[i == 0];
        }
    }
    else
    {
        for(int i = (n - 1) / 2; i >= 0; i--)
        {
            cout << arr[i] << " " << arr[n - 1- i] << " \n"[i == 0];    //this was a little tricky
        }
    }
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while( t-- )
        solve();
    return 0;
}
