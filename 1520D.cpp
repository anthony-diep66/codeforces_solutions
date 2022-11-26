#include<bits/stdc++.h>
using namespace std;
//the problem asks to count the number of (i, j) pairs such that i < j and a[j] - a[i] == j - i
//while brute force with n^2 can be achieved, the equation can be rearranged to: a[i] - i == a[j] - j.
//What this equation interpretes to is to find all pairs (i, j) such that the difference
//between the element and its index (a[j] - j) is equal to a previously calculated pair (i < j)
//https://www.youtube.com/watch?v=LURJnB0vuvs

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n; i++)
    {
        int t;
        cin >> t;
        arr[i] = t;
    }
    long long int res = 0;
    map<int, int> freq;
    for(int i = 0; i < arr.size(); i++)
    {
        /*
        * 1) Calculate i - arr[i]
        * 2) Take res, add to the number of preexisting pairs
        * 3) Increment the count of the differences
        */
        res += freq[i-arr[i]]++;        // once a frequency can be incremented, consider 
    }                                   // all the previously possible pairs added to all the newly possible pairs
    cout << res << endl;                // newly poss. pairs = for each element where freq matches, a new pair can be
}                                       // made with the i'th element

int main(void)
{
    //freopen("in.txt", "r", stdin);

    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while( t-- )
    {
        solve(); 
    }
    return 0;
}


