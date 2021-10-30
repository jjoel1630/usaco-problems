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
	setIO("lostcow");

	int N, K;
	cin >> N >> K;

	int pos = N;
	int count = 0;
	int addend = 1;

	if(N < K) {
		count++;
		addend++;
		pos++;

		// cout << count << " " << addend << " " << pos << "\n";

		while (pos < K) {
			if(pos > N) {
				// cout << count << " " << addend << " " << pos << "\n";
				count = count + (pos - (N - addend));
				pos = N - addend;
				addend = addend * 2;
				// cout << count << " " << addend << " " << pos << "\n";
			} else {
				// cout << count << " " << addend << " " << pos << "\n";
				count = count + min(K - pos, (addend + N) - pos);
				pos = pos + min(K - pos, (addend + N) - pos);
				addend = addend * 2;
				// cout << count << " " << addend << " " << pos << "\n";
			}
		}

		cout << count;
		return 0;
	}

	count++;
	addend++;
	pos++;

	while (pos > K) {
		if(pos > N) {
			count = count + min(pos - (N - addend), pos - K);
			pos = pos - min(pos - (N - addend), pos - K);
			addend = addend * 2;
		} else {
			count = count + ((N + addend) - pos);
			pos = N + addend;
			addend = addend * 2;
		}
	}

	cout << count;

	return 0;
}