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
	// setIO("hps");

	int N;
	cin >> N;

	int count1 = 0;
	int count2 = 0;

	for(int i = 0; i < N; i++) {
		int t, z;
		cin >> t >> z;

		if(t == 1 && z == 2) count1++;
		else if(t == 2 && z == 3) count1++;
		else if(t == 3 && z == 1) count1++;
		// else one.pb(false);

		if(t == 1 && z == 3) count2++;
		else if(t == 3 && z == 2) count2++;
		else if(t == 2 && z == 1) count2++;
		// else two.pb(false);
	}
		
	cout << max(count1, count2) << "\n";
}