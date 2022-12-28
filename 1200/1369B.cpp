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

// The solution will contain all leading 0's and all trailing 1's. Between the leading 0's and trailing 1's, there is a "10".
// The "10" is able to reduce any sized "middle" section down to either a "1" or a "0".
//              leading 0's   |    middle section with 10     | trailing 1's
// To make it lexicographically smallest, choose a 0 to put into answer.

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    size_t i = 0;
    vector<int> ans;
    //leading 0s
    while( i < s.size() && s[i] == '0' )
    {
        ans.push_back(0);
        i++;
    }
    //trailing ones
    size_t j = s.size() - 1;
    while( j >= 0 && s[j] == '1' )
    {
        ans.push_back(1);
        j--;
    }
    for(int i = 0; i < n - 1; i++)    //iterate over entire string to check whether 10 exists, print a '0' if it does.
    {
        if( s[i] == '1' && s[i+1] == '0' )
        {
            cout << 0; 
            break;
        }
    }

    for(int i : ans)
        cout << i;
    cout << endl;
}
int main(void)
{
    #define LOCAL
    #define TEST_CASES

    #ifdef LOCAL
        auto begin = std::chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    #ifdef TEST_CASES
        int t;
        cin >> t;
        while( t-- )
            solve();
    #else
        solve(); 
    #endif

    
    #ifdef LOCAL
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << 
            std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
            << " seconds" << endl;
    #endif
    return 0;
}

