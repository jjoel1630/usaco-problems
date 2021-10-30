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
	// setIO("proximity");
	map<int, int> m;

	int N, K;
	cin >> N >> K;

	int maxi = -1;

	for(int i=0; i<N; i++) {
		int t;
		cin >> t;
		
		if(m[t]  && i - m[t] <= K) {
			maxi = max(t, maxi);
			m[t] = i;
		}
		else m[t] = i;
	}

	cout << maxi;
}