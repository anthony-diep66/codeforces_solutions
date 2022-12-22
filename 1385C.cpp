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

/* This solution actually works but it's too inefficient. example of a greedy method of solving problem */
/* The actual solution is finding the max element and making sure each element to left is <= and all elements to right is laos <= */

int solve(vector<int> arr)
{
    auto ok = [=](vector<int> arr)
    {
        int l = 0, r = arr.size() - 1;
        int step = -INT_MAX;
        while( l <= r )
        {
            if( arr[l] <= arr[r] )
            {
                if( arr[l] >= step )
                {
                    step = arr[l];
                    l++;
                }
                else if( arr[r] >= step )
                {
                    step = arr[r];
                    r--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if( arr[r] >= step )
                {
                    step = arr[r];
                    r--;
                }
                else if( arr[l] >= step )
                {
                    step = arr[l];
                    l++;
                }
                else 
                {
                    return false;
                }
            }
        }
        return true;
        
    };
    if( ok(arr) )
        return 0;
    else
        return 1 + solve(vector<int>(arr.begin() + 1, arr.end()));
}

//key thought here is that a "good" array is sorted. Find peak of a_mx >= a_k-1 >= a_k. Then extend to left 
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
    int mx = n - 1;
    while( mx > 0 && arr[mx-1] >= arr[mx] )
        mx--;
    mx--;
    while( mx > 0 && arr[mx-1] <= arr[mx] )
        mx--;
    if( mx == -1 )    //all elements are same
        cout << 0 << endl;
    else
        cout << mx << endl;
}

int main(void)
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        cin >> n;
        vector<int> arr(n); 
        for(int i = 0, t; i < n; i++)
        {
            cin >> t;
            arr[i] = t;
        }
        cout << solve(arr) << endl;
    }
    return 0;
}


