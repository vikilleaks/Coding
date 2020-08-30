#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define pi pair<ll, ll>
#define endl "\n"
#define MAXN 100005
using namespace std;

ll n, m, vis[1005][1005];
char s[1005][1005];
pi mm[1005][1005];
ll r[] = {1, -1, 0, 0};
ll c[] = {0, 0, 1, -1};

bool check(ll x, ll y)
{
    if (x == 0 || y == 0 || x == n + 1 || y == m + 1)
        return 0;
    else
        return 1;
}

void bfs(ll a, ll b)
{
    queue<pi> q;
    q.push(mp(a, b));
    vis[a][b] = 1;
    while (!q.empty())
    {
        pi p = q.front();
        q.pop();
        ll x = p.ff, y = p.ss;
        for (ll i = 0; i < 4; i++)
        {
            if (check(x + r[i], y + c[i]) && !vis[x + r[i]][y + c[i]] && (s[x + r[i]][y + c[i]] == '.' || s[x + r[i]][y + c[i]] == 'B'))
            {
                mm[x + r[i]][y + c[i]] = mp(x,y);
                vis[x + r[i]][y + c[i]] = 1;
                q.push(mp(x + r[i], y + c[i]));
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    ll l1, r1, l2, r2;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == 'A')
            {
                l1 = i;
                r1 = j;
            }
            else if (s[i][j] == 'B')
            {
                l2 = i;
                r2 = j;
            }
        }
    }
    bfs(l1, r1);
    if (!vis[l2][r2])
    {
        cout << "NO" << endl;
        return;
    }
    pi temp = mm[l2][r2], temp2 = mp(l2, r2);
    string s = "";
    while (temp != mp(l1, r1))
    {
        if (temp2.ff - temp.ff == 1)
            s += "D";
        else if (temp2.ff - temp.ff == -1)
            s += "U";
        else if (temp2.ss - temp.ss == 1)
            s += "R";
        else
            s += "L";
        temp2 = temp;
        temp = mm[temp.ff][temp2.ss];
    }
    if (temp2.ff - temp.ff == 1)
        s += "D";
    else if (temp2.ff - temp.ff == -1)
        s += "U";
    else if (temp2.ss - temp.ss == 1)
        s += "R";
    else
        s += "L";
    reverse(s.begin(), s.end());
    cout << "YES" << endl;
    cout << s.size() << endl;
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
