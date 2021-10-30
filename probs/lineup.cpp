#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>


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

using LL = long long;
using VI = vector<int>;
using PII = pair<int,int>;
using PIS = pair<int, string>;
using PSS = pair<string, string>;
using VI = vector<int>;
using VS = vector<string>;
using VC = vector<char>;
using VB = vector<bool>;
using VII = vector<vector<int>>;
using MII = map<int, int>;
using MSI = map<string, int>;
using MSS = map<string, string>;
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

// map<string, VS> st {
// 	{"Beatrice", {}},
// 	{"Sue", {}},
// 	{"Belinda", {}},
// 	{"Bessie", {}},
// 	{"Betsy", {}},
// 	{"Blue", {}},
// 	{"Bella", {}},
// 	{"Buttercup", {}}
// };

vector<PSS> st;

VS cows {
	"Beatrice",
	"Sue",
	"Belinda",
	"Bessie",
	"Betsy",
	"Blue",
	"Bella",
	"Buttercup"
};

int main(){
	// setIO("lineup");

	sort(cows.begin(), cows.end());

	int N;
	cin >> N;


	for(int i = 0; i < N; i++) {
		string s1, s2, s6;
		
		cin >> s1 >> s2 >> s2 >> s2 >> s2 >> s6;

		st.pb(mp(s1, s6));
	}

	do {
		for(int i = 0; i < sz(cows); i++) {
			bool works = true;

			for(int j = 0; j < sz(st); j++) {
				int i1 = find(begin(cows), end(cows), st[j].x) - begin(cows);
				int i2 = find(begin(cows), end(cows), st[j].y) - begin(cows);

				// cout << i1 << " " << i2 << "\n";

				if(abs(i1 - i2) != 1) {
					works = false;
					break;
				}
			}

			if(works) {
				for(int j = 0; j < sz(cows); j++) cout << cows[j] << "\n";
				return 0;
			}
		}
    } while (next_permutation(all(cows)));


	// for (int i = 0; i < sz(sequences); i++) cout << cows[sequences[i]] << '\n';
}