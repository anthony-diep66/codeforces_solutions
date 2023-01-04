#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define all(x) (x).begin(), (x).end()

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) { cout << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t";
	err(++it, args...);
}

//sort the grid based on x first, then y second

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> grid(n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[i] = {x, y};
    }
    auto cmp = [=](const auto& left, const auto& right) -> bool
    {
        return left.first < right.first ||                                    // REMEMBER ME
            (left.first == right.first && left.second < right.second);
    };

    sort( grid.begin(), grid.end(), cmp );
    
    /*
    for(const auto& pair : grid)
        cout << pair.first << "\t" << pair.second << endl;
    cout << endl;
    */
    
    int lastx = 0, lasty = 0;
    string ans = "";
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].first - lastx; j++)
            ans += 'R';
        for(int j = 0; j < grid[i].second - lasty; j++)
            ans += 'U';
        if( grid[i].second < lasty )
        {
            cout << "NO\n";
            return;
        }
        lastx = grid[i].first;
        lasty = grid[i].second;
    }
    
    /* 
    for(const auto& pair : grid)
        cout << pair.first << "\t" << pair.second << endl;
    cout << endl;
    */
    
    cout << "YES\n" << ans << endl;
}

int main(void)
{
    //#define LOCAL
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

