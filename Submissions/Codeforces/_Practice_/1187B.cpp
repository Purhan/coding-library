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
// #define PI 3.1415926535897932384626
// const int MOD = 1000000007; const lli INF = 1e18; const int MX = 100001;

int n; string s;
map<char, queue<int>> mp;

void solve(map<char, queue<int>> m) {
    string name; cin >> name;

    int ans = 0;
    for (auto c : name) {
        int temp = m[c].front();
        ans = max(ans, temp);
        m[c].pop();
    }
    cout << ans + 1 << enl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    fo(int, i, 0, n) {
        mp[s[i]].push(i);
    }

    int testcase; cin >> testcase; for (int i = 1; i <= testcase; ++i)
        solve(mp);
    return 0;
}