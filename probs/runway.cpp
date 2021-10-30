#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
typedef vector<int> VI;
typedef map<int, int> MPII;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

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

//Global Variables:
void setIO(string name = "") { // name is nonempty for USACO file I/O
	ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
	if(sz(name)){
		freopen((name+".in").c_str(), "r", stdin); // see Input & Output
		freopen((name+".out").c_str(), "w", stdout);
	}
}
int checkChanges(vector<int> &t, vector<int> &p, int &s) {
	map<int, int> m;
	map<int, int> b;

	for(int i = 0; i < s; i++) {
		m[t[i]]++;
		b[p[i]]++;
	}

	int c = 0;
	for(auto &z : m) c += max(0, z.second - b[z.first]);

	return c;
}

int main(){
	setIO("file");

	int T;
	cin >> T;

	for(int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		vector<int> cameInWith;

		for(int k = 0; k < M; k++) cin >> cameInWith[k];

		vector<int> prev = cameInWith;
		int c = 0;
		for(int j = 0; j < N; j++) {
			vector<int> v;

			for(int k = 0; k < M; k++) cin >> v[k];

			c += checkChanges(prev, v, M);
		}
	}
}
