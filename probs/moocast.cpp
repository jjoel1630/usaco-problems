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
#define f first
#define s second
#define mp make_pair
//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

vector<vector<int>> v;

bool dist(int i, int j) {
	int dst = v[i][2];
	int a = abs(v[i][0] - v[j][0]);
	int b = abs(v[i][1] - v[j][1]);
	if(dst * dst >= a * a + b * b) return true;
	return false;
}

int dfs(int u, vector<bool>& vis) {
	if(vis[u]) return 0;
	vis[u] = true;
	int count = 1;
	for(int i = 0; i < (int)vis.size(); i++) {
		if(vis[i]) continue;
		if(dist(u, i)) {
			count += dfs(i, vis);
		}
	}
	return count;
}

void moocast() {
	setIO("moocast");

	int N;
	cin >> N;


	for(int i = 0; i < N; i++) {
		int x, y, p;
		cin >> x >> y >> p;

		v.push_back({x, y, p});
	}


	int mx = 0;

	for(int i = 0; i < N; i++) {
		vector<bool> vis(N, false);
		mx = max(mx, dfs(i, vis));
	}
	cout << mx << '\n';
}

int main(){
	moocast();
}