#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define pb push_back
#define rsz resize
#define mp make_pair
#define x first
#define y second

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define grid(name, x, y) name(x, vector<int>(y));
#define boolgrid(name, x, y) vector<vector<bool>> name(x, vector<bool> (y, false));
#define coutvect(name, n) for(int i = 0; i < n; i++){cout << name[i] << "\t";}
#define cout2dvect(name, n) for(int i = 0; i < n; i++){for(int j = 0; j < sz(name[i]); j++) {cout << name[i][j] << "\t";}}

using LL = long long;
using VI = vector<int>;
using PII = pair<int,int>;
using PIS = pair<int, string>;
using VI = vector<int>;
using VS = vector<string>;
using VC = vector<char>;
using VB = vector<bool>;
using VII = vector<vector<int>>;
using MII = map<int, int>;
using MSI = map<string, int>;
using MSB = map<string, bool>;
using MCI = map<char, int>;

//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int query(vector<vector<int>>& pref, int a, int b, int x) {
	return pref[b][x] - (a ? pref[a - 1][x] : 0);
}

int main(){
	setIO("bcount");

	int N, Q;
	cin >> N >> Q;
	
	VII pf(N);

	int b1 = 0;
	int b2 = 0;
	int b3 = 0;

	for(int i = 0; i < N; i++){
		int t;
		cin >> t;

		if(t == 1) b1++;
		if(t == 2) b2++;
		if(t == 3) b3++;

		pf[i] = {b1, b2, b3};
	}

	for(int i = 0; i < Q; i++){
		int a, b;
		cin >> a >> b;

		a--, b--;

		// if(pf[b - 1][0] == pf[b - 1][0]) cout << pf[b - 1][0] - 1 << " ";
		// if(pf[b - 1][1] == pf[b - 1][1]) cout << pf[b - 1][1] - 1 << " ";
		// if(pf[b - 1][2] == pf[b - 1][2]) cout << pf[b - 1][2] - 1 << " ";

		// cout << pf[b - 1][0] << " " << pf[b - 1][1] << " " << pf[b - 1][2] << "\n";
		cout << query(pf, a, b, 0) << " " << query(pf, a, b, 1) << " " << query(pf, a, b, 2) << '\n';
	}

}