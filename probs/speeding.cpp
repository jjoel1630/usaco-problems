#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

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

int main(){
	setIO("speeding");


	int N, K;
	cin >> N >> K;

	vector<PII> limit(N, mp(-1, -1));
	vector<PII> personal(K, mp(-1, -1));

	for(int i = 0; i < N; i++) cin >> limit[i].x >> limit[i].y; 
	for(int i = 0; i < K; i++) cin >> personal[i].x >> personal[i].y;

	int curlimit = limit[0].y, curspeed = personal[0].y, maxspeed = 0, cursegment = limit[0].x, speedsegment = personal[0].x;

	int l = 0, p = 0;
	for(int i = 1; i <= 100; i++) {
		if(i > cursegment) {
			l++;
			cursegment = cursegment + limit[l].x;
			curlimit = limit[l].y;
		}
		if(i > speedsegment) {
			p++;
			speedsegment = speedsegment + personal[p].x;
			curspeed = personal[p].y;
		}


		maxspeed = max(maxspeed, curspeed - curlimit);
	}

	cout << maxspeed;
}