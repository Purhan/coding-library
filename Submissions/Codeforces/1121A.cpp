#include <bits/stdc++.h>
using namespace std;
#define fo(int, i, a, b)        for (int i=a; i<(b); i++)
#define forev(int, i, b, a)     for (int i = (b)-1; i >= a; i--)
#define uns                     unsigned
#define lli                     long long int
#define ld                      long double
#define all(x)                  x.begin(), x.end()
#define sortall(x)              sort(all(x))
#define enl                     "\n"
#define dbg(x)                  cout << #x << ": " << x << enl;
// #define PI 3.1415926535897932384626
// const int MOD = 1000000007; const lli INF = 1e18; const int MX = 100001;

void solve() {
    int n, m, k, ans = 0; cin >> n >> m >> k;
    vector<int> p(n + 1), s(n + 1), chosen(k);
    int mp[m + 1] = {0};
    fo(int, i, 1, n + 1) cin >> p[i];
    fo(int, i, 1, n + 1) {
        cin >> s[i];
        int x = s[i];
        mp[x] = max(mp[x], p[i]);
    }
    fo(int, i, 1, k + 1) {
        cin >> chosen[i];
        int x = chosen[i];
        int y = s[x];
        if (mp[y] != p[x]) ans++;
    }
    cout << ans << enl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int testcase; cin >> testcase; for (int i = 1; i <= testcase; ++i)
    solve();
    return 0;
}