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
	// setIO("herding");

	int a, b, c;
	cin >> a >> b >> c;

	if(a + 1 == b && a + 2 == c && b + 1 == c) {
		cout << 0 << "\n" << 0;
		return 0;
	} else if(a + 2 == b || b + 2 == c) cout << 1 << "\n";
	else cout << 2 << "\n";

	// if(abs(c - b) % 2 == 0 && abs(b - a) % 2 == 0) 
	cout << max(abs(c - b), abs(b - a)) - 1;
	// else cout << max(abs(c - b), abs(b - a)) - 1;
}