#include <bits/stdc++.h>
using namespace std;

// this implementation uses path compression AND union by rank optimizations
// -> query = O( α(n) ) where  α(n) is the Ackermann function. This function is nearly constant for 
//            nearly all reasonable sizes n <= 10 ^ 600.
// without these optimizations, a query takes O( log n ) time
const int V;
bool parent[V];
int rank[V];
void make_set(int v)
{
    rank[v] = 0;
    parent[v] = v;
}

int find_set(int v)
{
    if( v == parent[v] )
    {
        return v;
    }
    return find_set(parent[v]);
}
void union_set(int ar, int br)
{
    int a = find_set(ar);
    int b = find_set(br);

    if( a != b )
    {
        if( rank[a] < rank[b] )
        {
            swap(a, b);
        }
        parent[b] = a;
        if( rank[a] == rank[b] )
        {
            rank[a]++;
        }
    }

}

int main(void)
{

  return 0;
}
