#include <bits/stdc++.h>
using namespace std;
#define fo(i, a, b) 	for (int i=a; i<(b); i++)
#define forev(i, b, a) 	for (int i = (b)-1; i >= a; i--)
typedef long long int	lli;
typedef long double		ld;
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define endl	"\n"
#define fast	ios_base::sync_with_stdio(0); cin.tie(0);
// #define PI 3.1415926535897932384626
// const int MOD = 1000000007; // const ll INF = 1e18; // const int MX = 100001;
//==================================================================================

int main() {
	fast;
	int t; cin >> t; while (t--) {
		lli n; cin >> n;
		lli ans = 0;
		for (int i = 1; i <= n / 2; ++i) {
			ans += (lli) i * i;
		}
		ans *= 8;

		cout << ans << endl;
	}

	return 0;
}