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
int main(){
	// setIO("traffic");

	int x = (int)-1e9, y = (int)1e9;

	int N;
	cin >> N;

	vector<string> st;
	vector<vector<int>> vt;

	for(int i = 0; i < N; i++) {
		int t, z;
		string s;

		cin >> s >> t >> z;

		vt.pb({t, z});
		st.pb(s);

		if(s == "on") {
			x += t;
			y += z;
		} else if(s == "off") {
			x -= z;
			y -= t;
		} else if(s == "none") {
			x = max(x, t);
			y = min(y, z);
		}
		x = max(x, 0);
		y = max(y, 0);
	}

	int x2 = 0, y2 = (int)1e9;

	for(int i = N - 1; i >= 0; i--) {
		if(st[i] == "off") {
			x2 += vt[i][0];
			y2 += vt[i][1];
		} else if(st[i] == "on") {
			// if(vt[i][0] > x2) x2 = vt[i][0];
			// if(vt[i][1] < y2) y2 = y2 - vt[i][1];
			// if((vt[i][0] <= x2) && (vt[i][1] >= y2)) {
			// 	cout << x2 << "\n";
			// }
			x2 -= vt[i][1];
			y2 -= vt[i][0];
			// x2 = max(x2, vt[i][0]);
			// y2 = min(y2, vt[i][1]);
		} else if(st[i] == "none") {
			x2 = max(x2, vt[i][0]);
			y2 = min(y2, vt[i][1]);
		}

		x2 = max(x2, 0);
		y2 = max(y2, 0);
	}
	cout << x2 << " " << y2 << "\n" << x << " " << y;
}