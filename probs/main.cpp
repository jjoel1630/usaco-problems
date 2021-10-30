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

void printMap(map<char, int> &m) {
	cout << "New Map\n";
	for(auto& x: m) {
		cout  << x.first << " : " << x.second << "\n";
	}
}

void cowsignal() {
	setIO("cowsignal");

	int M, N, K;
	cin >> M >> N >> K;

	for(int i = 0; i < M; i++) {
		string s;
		cin >> s;

		string temp;

		for(int j = 0; j < N; j++) {
			for(int k = 0; k < K; k++) {
				temp += s[j];
			}
		}

		for(int j = 0; j < K; j++) {
			cout << temp << "\n";
		}
	}
}

void blockgame() {
	setIO("blocks");

	int N;
	cin >> N;

	map<char, int> freqs;

	for(int i = 0; i < N; i++) {
		string s1;
		string s2;

		cin >> s1 >> s2;

		map<char, int> m1;
		map<char, int> m2;

		for(int j = 0; j < s1.length(); j++) m1[s1[j]]++;
		for(int j = 0; j < s2.length(); j++) m2[s2[j]]++;

		// printMap(m1);
		// printMap(m2);

		for(int j = 0; j < 26; j++) {
			char letter = 'a' + j;
			freqs[letter] += max(m1[letter], m2[letter]);			
		}
	}

	for(int i = 0; i < 26; i++) cout << freqs['a' + i] << "\n";
}

void outofplace() {
	setIO("outofplace");

	int N;
	cin >> N;

	vector<int> unsorted;
	vector<int> sorted;

	for(int i = 0; i < N; i++) {
		int t;
		cin >> t;
		unsorted.push_back(t);
		sorted.push_back(t);
	}

	sort(sorted.begin(), sorted.end());

	int count = 0;

	for(int i = 0; i < N; i++) if(sorted[i] != unsorted[i]) count++;

	cout << count -1;
}

void square() {
	setIO("square");

	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	int minh = min(x1, x3);
	int maxh = max(x2, x4);
	int minv = min(y1, y3);
	int maxv = max(y2, y4);

	int s1 = abs(minh - maxh);
	int s2 = abs(minv - maxv);

	cout << max(s1, s2) * max(s1, s2);
}

void billboard() {
	setIO("billboard");

	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	cin >> x5 >> y5 >> x6 >> y6;

	// area of box 1
	int ab1 = abs(x2 - x1) * abs(y2 - y1);
	// area  of box 2
	int ab2 = abs(x4 - x3) * abs(y4 - y3);

	if((x5 >= x4) || (x6 <= x1) || (max(y2, y4) <= y5) || (min(y1, y3) >= y6)) {
		cout << ab1 + ab2;
		return;
	}
	
	if(x6 <= x3) {
		int base1 = abs(max(x1, x5) - min(x2, x6));
		int height1 = abs(max(y1, y5) - min(y2, y6));
		int aoi1 = base1 * height1;

		cout << abs(ab1 - aoi1) + ab2;

		return;
	}

	if(x5 >= x2) {
		int base2 = abs(max(x3, x5) - min(x4, x6));
		int height2 = abs(max(y3, y5) - min(y4, y6));
		int aoi2 = base2 * height2;

		cout << abs(ab2 - aoi2) + ab1;

		return;
	}

	// area of intersection 1 
	int base1 = abs(max(x1, x5) - min(x2, x6));
	int height1 = abs(max(y1, y5) - min(y2, y6));
	int aoi1 = base1 * height1;


	// area of intersection 2
	int base2 = abs(max(x3, x5) - min(x4, x6));
	int height2 = abs(max(y3, y5) - min(y4, y6));
	int aoi2 = base2 * height2;

	cout << abs(ab2 - aoi2) + (ab1 - aoi1);
}

void lifeguard() {
	setIO("lifeguards");

	int time[1001];

	for(int i = 0; i <= 1000; i++) time[i] = 0;

	int N;
	cin >> N;

	int start[N];
	int end[N];

	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		for(int j = a; j < b; j++) time[j]++;
		start[i] = a;
		end[i] = b;
	}

	int maxCount = 0;
	for(int i = 0; i < N; i++) {
		for(int j = start[i]; j < end[i]; j++) if(time[j] > 0) time[j]--;

		int count = 0;
		for(int j = 0; j <= 1000; j++) if(time[j] > 0) count++;

		for(int j = start[i]; j < end[i]; j++) time[j]++;

		maxCount = max(count, maxCount);
	}

	cout << maxCount;
}

vector<vector<int>> v;

bool dist(int i, int j) {
	int dst = v[i][2];
	int a = abs(v[i][0] - v[j][0]);
	int b = abs(v[i][1] - v[j][1]);
	if(dst * dst >= a * a + b * b) return true;
	return false;
}

int dfs(int u, vector<bool>& vis) {
	if(vis[u]) return 0;
	vis[u] = true;
	int count = 1;
	for(int i = 0; i < (int)vis.size(); i++) {
		if(vis[i]) continue;
		if(dist(u, i)) {
			count += dfs(i, vis);
		}
	}
	return count;
}

void moocast() {
	setIO("file");

	int N;
	cin >> N;


	for(int i = 0; i < N; i++) {
		int x, y, p;
		cin >> x >> y >> p;

		v.push_back({x, y, p});
	}


	int mx = 0;

	for(int i = 0; i < N; i++) {
		vector<bool> vis(N, false);
		mx = max(mx, dfs(i, vis));
	}
	cout << mx << '\n';
}

int main(){
	moocast();
}