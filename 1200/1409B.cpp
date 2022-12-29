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


// this solution brute forces the possible number of common differences between the two given numbers
void solve_alternative()
{
    int n, x, y;
    cin >> n >> x >> y;
    int upper = y - x;
    if( n < 3 )
    {
        cout << x << " " << y << endl;
        return;
    }
    for(int diff = 1; diff <= upper; diff++)
    {
        int count = 0;
        vector<int> ans;
        for(int i = x + diff; i < y; i+=diff)   //count the number of integers between given
            count++;
        //cout << "diff = " << diff << "\tmath: " << x + (count * (diff+1)) << "\tcount = " << count << endl;
        if( x + (count * diff) + diff != y )  // if the common difference * the number of numbers between does not equal y, continue
            continue;
        if( count + 2 == n )              // if the number of numbers between plus the given two is exactly equal to n, that means x was first, y was last
        {
            for(int i = x; i <= y; i+=diff)
                cout << i << " \n"[i == y];
            return;
        }
        else if( count + 2 < n )    // if the number of integers between is less (most probable)
        {
            deque<int> res;       //didn't actually need this, could've done with vector
            //in between
            for(int i = x; i <= y; i+=diff)  
                res.push_back(i);
            //left of x
            for(int i = 1; res.size() < n && x - (i * diff) > 0 ; i++)
                res.push_back(x - (i * diff));
            
            //right of y
            for(int i = y + diff; res.size() < n; i+=diff)
                res.push_back(i);

            while( !res.empty() )
            {
                cout << res.front() << " ";
                res.pop_front();
            }
            cout << endl;
            return;
        }
    }

}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    // a_n = a_1 + (n - 1) * d
    // d = (a_n - a_1) / n - 1
    // n - 1 | (a_n - a_1) => (a_n - a_1) = (n - 1) * d
    if( n < 3 )
    {
        cout << x << " " << y << endl;
        return;
    }
    int d;
    for(int i = 1; i <= y - x; i++)
    {
        //cout << "i = " << "\t(y - x) / i + 1 = " << "(" << y << "-" << x << ")" << "/" << i << "+1 = " << (y-x)/i + 1 << endl;
        if( (y - x) % i == 0 && (y - x) / i < n )   // the common difference divides the difference of the two givens
        {                                           // if the difference between the two givens divided by the common divisor is less than n
            d = i;
            break;                                  // basically what was trying to be done in line 32 - 43
        }
    }
    vector<int> ans;
    for(int i = x; i <= y; i+=d)
    {
        ans.push_back(i); 
    }
    int mult = 1;
    while( x - (d * mult) > 0 && ans.size() < n )
    {
        ans.push_back(x - (mult * d));
        mult++;
    }
    mult = 1;
    while( ans.size() < n )
    {
        ans.push_back(y + (mult * d));
        mult++;
    }
    for(int i : ans)
        cout << i << " ";
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
