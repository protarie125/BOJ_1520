#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int m, n;
vvi dat;

const auto dx = vi{ 1, 0, -1, 0 };
const auto dy = vi{ 0, 1, 0, -1 };

ll ans;
vvi dp;

int part(int y, int x) {
	if (m - 1 == y && n - 1 == x) {
		return 1;
	}

	if (-1 != dp[y][x]) {
		return dp[y][x];
	}

	dp[y][x] = 0;
	for (auto d = 0; d < 4; ++d) {
		const auto nx = x + dx[d];
		const auto ny = y + dy[d];

		if (nx < 0 || n <= nx ||
			ny < 0 || m <= ny) {
			continue;
		}

		if (dat[ny][nx] < dat[y][x]) {
			dp[y][x] += part(ny, nx);
		}
	}

	return dp[y][x];
}

void solve() {
	ans = part(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> m >> n;

	dat = vvi(m, vi(n));
	for (auto&& rows : dat) {
		for (auto&& x : rows) {
			cin >> x;
		}
	}

	ans = 0;
	dp = vvi(m, vi(n, -1));
	solve();

	cout << ans;

	return 0;
}