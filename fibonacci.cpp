#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<ll,ll>
#define endl "\n"
#define MAXN 100005
using namespace std;

ll n, m=1e9+7;
vector<vector<ll> > F={{0,1},{1,1}};

void mult(vector<vector<ll> > &F, vector<vector<ll> > &M)
{
    ll x =  ((F[0][0] * M[0][0])%m + (F[0][1] * M[1][0])%m)%m;
    ll y =  ((F[0][0] * M[0][1])%m + (F[0][1] * M[1][1])%m)%m;
    ll z =  ((F[1][0] * M[0][0])%m + (F[1][1] * M[1][0])%m)%m;
    ll w =  ((F[1][0] * M[0][1])%m + (F[1][1] * M[1][1])%m)%m;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void matexp(vector<vector<ll> > &F, ll y)
{
    vector<vector<ll> > res={{1,0},{0,1}};
    while(y>0)
    {
        if(y%2==1) mult(res,F);
        mult(F,F);
        y/=2;
    }
    F[0][0] = res[0][0];
    F[0][1] = res[0][1];
    F[1][0] = res[1][0];
    F[1][1] = res[1][1];
}

// [Fn Fn+1] = [F0 F1] * ([[0 1],[1 1]]^n)
void solve()
{
    cin>>n;
    matexp(F,n);
    cout<<F[1][0]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
