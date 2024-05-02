#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cout << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
      cout << *it << "=" << a << "\t";
      err(++it, args...);
}
#define errorv(container) print_container(#container, container)
template<typename C>
void print_container(const char* name, const C& container) {
  std::cout << name << "=";
  bool first = true;
  std::stringstream ss;
  for(const auto &x : container) {
      if (!first) {
          ss << ",";
      }
      first = false;
      ss << x;
  }
  std::cout << '{' << ss.str() << '}' << std::endl;
}

ull binpow(ull a, ull b, ull m) {
  ull res = 1;
  a%=m;
  while( b > 0 ) {
    if( b & 1 )
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
  }
  return res;
}

ull binpow(ull a, ull b) {
  ull res = 1;
  while( b > 0 ) {
    if( b & 1 )
      res *= a;
      a *= a;
      b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  set<pair<int, int>> at;
  for(int i = 0; i <= n - m; i++) {
    int k = 0;
    for(int j = i; j < i + m; j++, k++) {
      if( s[j] != t[k] ) break;
      if( s[j] == t[k] && j == i + m - 1 ) {
        at.insert({i, i + m - 1});
      }
    }
  }

  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    int count = 0;
    for(auto it = at.begin(); it != at.end(); ++it) {
      if( (a <= it->first) && (it->second <= b) ) {
        count++;
      }
    }
    cout << count << endl;
  }

}

void USACO_IO(string filename);
int main(void) {
  //USACO_IO("shuffle");
  #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
  #endif


  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  solve();

  #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << 
        std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() 
        << " seconds" << endl;
  #endif

  return 0;
}

void USACO_IO(string filename) {
  string in = filename + ".in";
  string out = filename + ".out";
  freopen(in.c_str(), "r", stdin);
  freopen(out.c_str(), "w", stdout);
}

