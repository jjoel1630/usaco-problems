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
	setIO("revegetate");

	int N, M;
	cin >> N >> M;

	vector<pi> v;
	for(int i = 0; i < M; i++) {
		int t, z;
		cin >> t >> z;

		v.pb({t, z});
	}

	// string ret = "";
	// for(int i = 0; i < N; i++) {
	// 	vector<bool> cur = {true, true, true, true};

	// 	for(int j = 0; j < M; j++) {
	// 		if(v[j].first == i + 1 or v[j].second == i + 1) {
	// 			int othr = v[j].first ^ v[j].second ^ (i + 1);
	// 			if(othr < i + 1) {
	// 				othr--;
	// 				cur[ret[othr] - '0'] = false;
	// 			}
	// 		}
	// 	}
	// 	for(int j = 0; j < 4; j++) {
	// 		if(cur[j]) {ret.append(1, (char)('0' + i)); break;}
	// 	}
	// }

	// cout << ret << '\n';

	string s = "";

	for(int i = 0; i < N; i++) {
		vector<bool> b{true, true, true, true};

		for(int j = 0; j < M; j++) {
			if(v[j].first == i + 1 || v[j].second == i + 1) {
				int pasture = v[j].first ^ v[j].second ^ (i + 1);
				// cout << v[j].first << " " << v[j].second << " " << i + 1 << " " << othr << "\t";
				if(pasture < i + 1) b[s[pasture - 1] - '0'] = false;
			}

		}

		for(int j = 1; j <= 4; j++) {
			if(b[j]) {
				s.append(1, (char)('0' + j));
				break;
			}
		}

		// cout << "\n";
	}

	cout << s;
}