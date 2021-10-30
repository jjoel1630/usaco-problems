/*
ID: varunra2
LANG: C++
TASK: word_hunt
*/

#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "lib/debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define debug_arr(...) \
  cerr << "[" << #__VA_ARGS__ << "]:", debug_arr(__VA_ARGS__)
#pragma GCC diagnostic ignored "-Wsign-compare"
//#pragma GCC diagnostic ignored "-Wunused-parameter"
//#pragma GCC diagnostic ignored "-Wunused-variable"
#else
#define debug(...) 42
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
#pragma GCC diagnostic ignored "-Wsign-compare"
// util functions

map<string, bool> there;
map<string, int> cnt;
vector<vector<char>> grid(4, vector<char>(4));

void proc(string& x) {
  there[x] = true;
  for(int i = 0; i < sz(x); i++) {
    cnt[x.substr(0, i + 1)]++;
  }
}

vector<pair<int, string>> words;

// VI dx = {-1, 0, 1};

void dfs(int i, int j, vector<vector<bool>>& vis, string& cur) {
  if(i < 0 or j < 0 or i >= 4 or j >= 4) return;
  if(vis[i][j]) return;
  vis[i][j] = true;
  cur.append(1, grid[i][j]);

  cout << cur << "\n";

  if(there[cur]) words.PB(MP(sz(cur), cur));
  if(cnt[cur] == 0) {vis[i][j] = false; cur.pop_back(); return;}

  for(int a = -1; a <= 1; a++) {
    for(int b = -1; b <= 1; b++) {
      dfs(i + a, j + b, vis, cur);
    }
  }

  vis[i][j] = false;
  cur.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("word_hunt.in", "r", stdin);
  freopen("word_hunt.out", "w", stdout);
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> grid[i][j];
    }
  }

  int n;
  cin >> n;



  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    proc(s);
  }


  vector<vector<bool>> vis(4, vector<bool> (4, false));

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      string s = "";
      dfs(i, j, vis, s);
    }
  }

  sort(all(words), greater<pair<int, string>>());

  for(int i = 0; i < sz(words); i++) cout << words[i].y << '\n';


  return 0;
}
