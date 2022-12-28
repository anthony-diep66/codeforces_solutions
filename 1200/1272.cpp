#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define all(x) (x).begin(), (x).end()

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

// keep an internal tracker "count" that keeps track of how a long a valid substring is. Once a substring with an invalid character
// is found, plug "count" into n * (n - 1) / 2 formula. After that, set "count" back to zero for next iteration. At the end,
// the for loop would have finished if the last character in string is invalid. So, add the current count value at the end in
// casees for those.

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<char> arr(n);
    set<char> seen;
    char t;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        arr[i] = t;
    }
    for(int i = 0; i < k; i++)
    {
        cin >> t;
        seen.insert(t);
    }
    
    ull ans, count;
    ans = count = 0;
    for(int i = 0; i < n; i++)
    {
        if( seen.count(arr[i]) != 0 )
        {
            count++;
        }
        else
        {
            ans += count * (count + 1) / 2;
            count = 0;
        }
    }
    ans += count * (count + 1) / 2;
    cout << ans << endl; 
}
int main(void)
{
    //#define LOCAL
    #ifdef LOCAL
        auto begin = std::chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    #ifdef LOCAL
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << 
            std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
            << " seconds" << endl;
    #endif
    return 0;
}
