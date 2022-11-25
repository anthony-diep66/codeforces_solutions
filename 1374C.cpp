#include<bits/stdc++.h>
using namespace std;


//strategy here is to match as many brackets inside a stack. After the string is done looping, the number of moves
//is equal to the number of unmatched brackets / 2. Divide by two because matching a bracket will reduce the size by
//2 each time.
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<char> s;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if( s.empty() )
        {
            s.push(str[i]);
            count++;
        }
        else if( s.top() == '(' && str[i] == ')' )    //matches the parenthesis here
        {
            --count;
            s.pop();
        }
        else
        {
            ++count;
            s.push(str[i]);
        }
    }
    cout << count / 2 << endl;
}


int main(void)
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while( t-- )
    {
        solve();
    }
    return 0;
}


