#include<bits/stdc++.h>
using namespace std;
//this is a binary search problem that considers searching through groups of elements
//setting up "possible answers" and finding the first value that is greater than or equal to target
//I think theoretically works but it is not efficient enough (some parameters will go over 1000ms).

//trick is to realize that there are other ways to check whether element is in group, not just psum[m] == target

void solve()
{
    int n, t;
    cin >> n;
    vector<int> psum(n);
    cin >> t;
    psum[0] = t;
    for(int i = 1; i < n; i++)
    {
        cin >> t;
        psum[i] = psum[i-1] + t;
    }
    int nq, q;
    cin >> nq;
    auto binsearch = [=](int target)    //lambda!
    {
        int l = 0, r = psum.size() - 1, m;
        while( l <= r )
        {
            m = l + (r - l) / 2;
          
            /* Here, if psum[m] was only checked, than that would mean we're only checking whether target happens to be equal
             * to the current pile total. This works, but you could also check if it's in the pile by noticing that psum[idx]
             * represents the pile before PLUS the current. To check, target will be strictly greater than pile total before
             * and target will be less than the mth pile. 
             * This was the hardest part of the problem
             */
            if( psum[m] == target || (target > psum[m-1] && target < psum[m] ) )  
            {                                                                     
                return m+1;                                                      
            }
            else if( m == 0 && target < psum[0] )   //also, since m-1 is being checked, m = 0 needs to be handled. Do a special else if for this
            {
                return 1;
            }
            else 
            {
                if( psum[m] < target )
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    };
    while( nq-- )
    {
        cin >> t;
        cout << binsearch(t) << endl;
    }
}

int main(void)
{
    //freopen("in.txt", "r", stdin);

    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve(); 
    return 0;
}


