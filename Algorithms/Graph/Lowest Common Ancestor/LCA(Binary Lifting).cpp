// This is an improved version of the naive approach for the LCA problem
// Instead of jumping nodes directly, we can jump nodes in power of 2, reducing time complexity from N to logN
// This idea is quite similar to the sparse table data structure
// Can replace tin and tout with a depth array

#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;
const int MAX_N = 100000 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

int N, Q, dp[MAX_N][MAX_L + 1], tin[MAX_N], tout[MAX_N], timer = 0;
vector<int> adj[MAX_N];

void dfs(int u, int p) { // dfs to fill in the 2^k ancestors of each node
    tin[u] = timer++;
    dp[u][0] = p; // direct parent (2^0 = 1)

    for (int i = 1; i <= MAX_L; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1];

    for (int v : adj[u])
        if (v != p)
            dfs(v, u);

    tout[u] = timer++;
}

bool is_ancestor(int u, int v){ // check if u is an ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int ancestor(int u, int k) { // return the k-th ancestor of node u, return 0 if does not exist
    for (int i = 0; i <= MAX_L && u != 0; i++)
        if (k & (1 << i)) // represent k in binary base and move on power of 2
            u = dp[u][i];
    return u;
}

int LCA(int u, int v) {
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;

    for (int i = MAX_L; i >= 0; i--)
        if (!is_ancestor(dp[u][i], v))
            u = dp[u][i];

    return dp[u][0];
}

int LCA(int u, int v) { // dep[u] < dep[v]
    if (dep[u] > dep[v]) swap(u, v);
    // advance v by dep[v] - dep[u] parents
    v = ancestor(v, dep[v] - dep[u]);

    if (u == v) return u;
    // u and v are at the same depth now
    // advance them together in power of 2
    for (int i = MAX_L; i >= 0; i--)
        if (dp[u][i] != dp[v][i])
            u = dp[u][i], v = dp[v][i];

    return dp[u][0];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> N >> Q;
    for(int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    while(Q--) {
        int u, v; cin >> u >> v;
        printf("LCA of %d and %d is %d\n", u, v, LCA(u, v));
    }
}
