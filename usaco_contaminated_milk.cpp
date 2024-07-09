void solve() {
  int N, M, D, S;
  cin >> N >> M >> D >> S;
  vector<vector<pair<int,int>>> events(N+1, vector<pair<int,int>>());
  for(int i = 0; i < D; i++) {
    int n, m, t;
    cin >> n >> m >> t;
    events[n].push_back(make_pair(m, t));
  }  
  vector<int> sick(N+1, 0);
  for(int i = 0; i < S; i++) {
    int n, t;
    cin >> n >> t;
    sick[n] = t;
  }

  set<int> defnotbad;
  set<int> maybebad;

  for(int person = 1; person <= N; person++) {
    if( !sick[person] ) continue;
    set<int> dranked;
    for(int i = 0; i < events[person].size(); i++) {
      if( events[person][i].second < sick[person] ) {
        maybebad.insert(events[person][i].first);
        dranked.insert(events[person][i].first);
      } else {
        defnotbad.insert(events[person][i].first);
      }
    }
    for(int milk = 1; milk <= M; milk++) {
      if( dranked.count(milk) == 0 )
        defnotbad.insert(milk);
    }
  }
  set<int> bad;
  for(int x : maybebad) 
    if( defnotbad.count(x) == 0 )
      bad.insert(x);

  set<int> gotsick;
  for(int person = 1; person <= N; person++) {
    for(int i = 0; i < events[person].size(); i++) {
      if( bad.count(events[person][i].first) == 1 ) {
        gotsick.insert(person);
      }
    }
  }

  cout << gotsick.size() << endl;
}
