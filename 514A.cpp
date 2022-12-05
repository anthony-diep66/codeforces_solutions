#include<bits/stdc++.h>
using namespace std;


//this is an alternative solution. Consider each character with reference, if character is greater than 
//or equal to '5', then change. At the end, the 0th index might be a '0', if it is, then we know that
//the input was a '9' originally so change it back to a '9'.
void alt_solve()
{
    string s;
    cin >> s;
    for(char &c : s)
    {
        if( c >= '5' )
        {
            /*
            cout << "c = " << (int)c  << endl;
            cout << "9 = " << (int)'9' << endl;
            cout << "original = " << (int)('9' - c) << endl;  // -> ASCII = 2. This is not what we want
            
            //below is correct way to substract characters
            cout << "modified = " << (int)('9' - (c - '0')) << endl;      //whenever subtraction with char are being done, make sure to subtract '0' first
            */
            c = '9' - (c - '0');
        }
    }
    if( s[0] == '0' )
        s[0] = '9';
    cout << s << endl;
}


void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
    }

    bool sign;
    int mx = -INT_MAX;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        bool nsign = (arr[i] < 0) ? 0 : 1;
        bool opp = ~nsign;
        while( opp == nsign )
        {
            if( arr[i] > mx )
            {
                opp ^= 1;
                mx = arr[i];
            }
            ++i;
        }

    }
}


int main(void)
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}


