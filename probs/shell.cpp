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
	// setIO("shell");

	int N;
	cin >> N;

	vector<int> guesses;
	int state[] = {1, 2, 3};

	for(int	i = 0; i < N; i++) {
		int a, b, g;
		cin >> a >> b >> g;

		int temp = state[a-1];
		state[a-1] = state[b-1];
		state[b-1] = temp;

		guesses.pb(state[g-1]);
	}
	
	map<int, int> freqs;
	for(int i = 0; i < guesses.size(); i++) {
		freqs[guesses[i]]++;
	}

	// for(auto &s : freqs) {
	// 	cout << s.first << " " << s.second << endl;
	// }

	int maxi = 0;
	for(auto &s : freqs) {
		maxi = max(s.second, maxi);
	}

	cout << maxi;
}