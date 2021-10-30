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
	// setIO("buckets");

	pi r;
	pi b;
	pi l;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			char f;
			cin >> f;
			if(f == 'R') r = mp(i, j);
			else if(f == 'B') b = mp(i, j);
			else if(f == 'L') l = mp(i, j);
		}
	}

	// cout << b.first << " " << b.second << "\n";
	// cout << l.first << " " << l.second << "\n";
	// cout << r.first << " " << r.second << "\n";
	int y = abs(b.first - l.first);
	int x = abs(b.second - l.second);
	// cout << y << " " << x;

	if(b.first == r.first && b.first == l.first && (min(b.second, l.second) < r.second && max(b.second, l.second) > r.second)) {
		// cout << "1\t";
		cout << x + 1;
		return 0;
	} else if(b.second == r.second && b.second == l.second && (min(b.first, l.first) < r.first && max(b.first, l.first) > r.first)) {
		// cout << "2\t";
		cout << y + 1;
		return 0;
	} else if((abs(b.second - l.second) == 1 && b.first == l.first)|| (abs(b.first - l.first) == 1 && b.second == l.second)) {
		// cout << "3\t";
		cout << 2;
		return 0;
	} else if(b.second == l.second) {
		// cout << "4\t";
		cout << y - 1;
		return 0;
	} else if(b.first == l.first) {
		// cout << "5\t";
		cout << x - 1;
		return 0;
	}

	cout << y + x - 1;
}