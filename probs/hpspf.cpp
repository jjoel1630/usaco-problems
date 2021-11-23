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
	setIO("hps");

	int N;
	cin >> N;

	VC v(N);
	for(int i=0; i<N; i++) cin >> v[i];

	vector<VI> pf(N,  {0, 0, 0});
	vector<VI> sf(N,  {0, 0, 0});

	if(v[0] == 'P') pf[0][0]++;
	else if(v[0] == 'H') pf[0][1]++;
	else pf[0][2]++;

	for(int i=1; i< N; i++) {
		if(v[i] == 'P') {
			pf[i][0] = pf[i - 1][0] + 1;
			pf[i][1] = pf[i - 1][1];
			pf[i][2] = pf[i - 1][2];
		}
		else if(v[i] == 'H') {
			pf[i][0] = pf[i - 1][0];
			pf[i][1] = pf[i - 1][1] + 1;
			pf[i][2] = pf[i - 1][2];
		}
		else {
			pf[i][0] = pf[i - 1][0];
			pf[i][1] = pf[i - 1][1];
			pf[i][2] = pf[i - 1][2] + 1; 
		}
	}

	if(v[N - 1] == 'P') sf[0][0]++;
	else if(v[N - 1] == 'H') sf[0][1]++;
	else sf[0][2]++;

	int j = 1;
	for(int i=N - 2; i >= 0; i--) {
		if(v[i] == 'P') {
			sf[j][0] = sf[j - 1][0] + 1;
			sf[j][1] = sf[j - 1][1];
			sf[j][2] = sf[j - 1][2];
		}
		else if(v[i] == 'H') {
			sf[j][0] = sf[j - 1][0];
			sf[j][1] = sf[j - 1][1] + 1;
			sf[j][2] = sf[j - 1][2];
		}
		else {
			sf[j][0] = sf[j - 1][0];
			sf[j][1] = sf[j - 1][1];
			sf[j][2] = sf[j - 1][2] + 1; 
		}

		j++;
	}

	// for(int i = 0; i < N; i++) cout << pf[i][0] << "\t" << pf[i][1] << "\t" << pf[i][2] << "\n";
	// cout << "\n";
	// for(int i = 0; i < N; i++) cout << sf[i][0] << "\t" << sf[i][1] << "\t" << sf[i][2] << "\n";

	VI mpf(N);
	for(int i = 0; i < N; i++) {
		int t = max(pf[i][0], pf[i][1]);
		mpf[i] = max(t, pf[i][2]);
	}

	VI msf(N);
	for(int i = 0; i < N; i++) {
		int t = max(sf[i][0], sf[i][1]);
		msf[i] = max(t, sf[i][2]);
	}
	reverse(all(msf));

	int mx = -1e9;
	for(int i = 0; i < N; i++) mx = max(mx, msf[i] + mpf[i]);

	cout << mx << "\n";
}