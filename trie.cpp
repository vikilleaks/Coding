#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MAXN 2000005
using namespace std;
using namespace __gnu_pbds;  

ll q,x;
char c;

typedef struct TrieNode
{
	map<ll,TrieNode*> m;
	ll cnt;
	bool end;
} Node;

Node* initNode()
{
	Node* t = new Node;
	t->m.clear();
	t->cnt=0;
	t->end=false;
	return t;
}

void insert(Node* root, ll x)
{
	Node* t = root;
	ll p;
	for(ll i=31;i>=0;i--)
	{
		(x&(1<<i))? p=1:p=0;
		if(!t->m[p]) t->m[p] = initNode();
		t = t->m[p];
		t->cnt++;
	}
	t->end=true;
}

void remove(Node* root, ll x)
{
	Node* t = root;
	ll p;
	for(ll i=31;i>=0;i--)
	{
		(x&(1<<i))? p=1:p=0;
		t = t->m[p];
		t->cnt--;
	}
	t->end=false;
}

ll check(Node* root, ll x)
{
	Node* t = root;
	ll p,res=0;
	for(ll i=31;i>=0;i--)
	{
		(x&(1<<i))? p=1:p=0;
		if(t->m[1-p] && t->m[1-p]->cnt>0)
		{
			t=t->m[1-p];
			res+=(1<<i);
		}
		else t=t->m[p];
	}
	return res;
}

void solve()
{
	Node* root = initNode();
	insert(root,0);
	cin>>q;
	while(q--)
	{
		cin>>c>>x;
		if(c=='+') insert(root,x);
		if(c=='-') remove(root,x);
		if(c=='?')	cout<<check(root,x)<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
