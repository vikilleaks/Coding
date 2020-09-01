#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll, ll>
#define endl "\n"
#define MAXN 505
using namespace std;

ll n, m, q, a, b, c, dp[MAXN][MAXN];

// The graph may have negative weight edges, but no negative weight cycles (for then the shortest path is undefined).
// This algorithm can also be used to detect the presence of negative cycles. 
// The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.
// T=O(n^3)

void solve()
{
    cin >> n >> m >> q;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            // Initialise distance matrix.
            (i == j) ? dp[i][j] = 0 : dp[i][j] = ll_MAX;
        }
    }
    while (m--)
    {
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b],c);
        dp[b][a] = min(dp[a][b],c);
    }
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                // If graph has negative weight egdes, INF-1, INF-2,... may be considered optimal which is incorrect.
                if (dp[i][k] < ll_MAX && dp[k][j] < ll_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    while (q--)
    {
        cin >> a >> b;
        if (dp[a][b] == ll_MAX)
            cout << -1 << endl;
        else
            cout << dp[a][b] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
