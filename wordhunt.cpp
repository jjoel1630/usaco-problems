#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define x first
#define y second
#define mp make_pair
//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}
// int main(){
// 	// setIO("file");

// 	string n = "hello";

// 	vector<vector<bool>> vis(4, vector<bool> (4, false));
// 	for(int i = 0; i < vis.size(); i++) {
// 		for(int j = 0; j < vis[i].size(); j++) {
// 			cout << vis[i][j] << "\t";
// 		}

// 		cout << "\n";
// 	}

// 	// cout << n.substr(0, 3) << "\n";
// }

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

  if(there[cur]) words.pb(mp(sz(cur), cur));
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
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> grid[i][j];
		}
	}

	setIO("usa");

	int n;
	cin >> n;


	
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		proc(s);
	}

	// for (auto& kv : cnt) {
	// 	cout << kv.first << " -> " << kv.second << "\n";
	// }


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