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
	setIO("mixmilk");

	int b1, cap1, b2, cap2, b3, cap3;

	cin >> cap1 >> b1;
	cin >> cap2 >> b2;
	cin >> cap3 >> b3;

	int proc = 1;

	for(int i = 1; i <= 100; i++){
		if(proc == 1) {
			proc++;

			if(b2 + b1 > cap2) {
				int t = abs(cap2 - b2);
				if(t >= b1) {
					b2 = b2 + b1;
					b1 = 0;
				} else if(t < b1) {
					b2 = b2 + t;
					b1 = b1 - t;
				}
			} else if(b2 + b1 <= cap2) {
				b2 = b2 + b1;
				b1 = 0;
			}
		} else if(proc == 2) {
			proc++;

			if(b3 + b2 > cap3) {
				int t = abs (cap3 - b3);
				if(t >= b2) {
					b3 = b3 + b2;
					b2 = 0;
				} else if(t < b2) {
					b3 = b3 + t;
					b2 = b2 - t;
				}
			} else if(b3 + b2 <= cap3) {
				b3 = b3 + b2;
				b2 = 0;
			}
		} else if(proc == 3) {
			proc = 1;

			if(b1 + b3 > cap1) {
				int t = abs(cap1 - b1);
				if(t >= b3) {
					b1 = b1 + b3;
					b3 = 0;
				} else if(t < b3) {
					b1 = b1 + t;
					b3 = b3 - t;
				}
			} else if(b1 + b3 <= cap1) {
				b1 = b1 + b3;
				b3 = 0;
			}
		}
	}

	cout << b1 << "\n";
	cout << b2 << "\n";
	cout << b3 << "\n";
}