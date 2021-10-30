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
	// setIO("shuffle");	

	int N;
	cin >> N;

	map<int, int> shuffles;
	vector<int> ending;
	long output[N + 1];

	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;

		shuffles[t] = i;
	}

	// for (const auto& p : shuffles ) {
    //     cout << p.first << " " << p.second << "\n";
    // }

	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		ending.push_back(t);
	}

	// for(int i = 0; i < N; i++) {
	// 	cout << ending[i];
	// }

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < N; j++) {
			// cout << shuffles[j + 1] << "\t";
			output[shuffles[j + 1]] = ending[j];
		}

		for(int j = 0; j < N; j++) {
			ending[j] = output[j];
		}

		// cout << "\n";
	}

	for(int i = 0; i < N; i++) {
		cout << output[i] << "\n";
	}
}