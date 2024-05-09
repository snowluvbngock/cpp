#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define fi first
#define se second
#define maxn 100005
using namespace std;

ll MOD, op , u , v;
ll arr[maxn];

int n,m;

struct node
{
    ll ma1,ma2;
}t[4*maxn];

ll mul(ll a,ll b,ll MOD)
{
    ll ans = 0;
    while(b)
    {
        if(b&1)(ans += a)%MOD;
        (a*=2)%MOD;
        b/=2;
    }
    return ans%MOD;
}

node ghep(node a , node b)
{
    node kqt;
    vector<ll> vtt = {a.ma1,a.ma2,b.ma1,b.ma2};
    sort(vtt.begin(),vtt.end(),greater<int>());
    kqt.ma1 = vtt[0];
    kqt.ma2 = vtt[1];
    return kqt;
}
void build(int id , int l , int r)
{
    if(l == r)
    {
        t[id].ma1 = arr[l];
        t[id].ma2 = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = ghep(t[id*2],t[id*2+1]);
}
node lay(int id , int l , int r , int u , int v)
{
    if(v < l || r < u)return {1,1};
    if(u <= l && r <= v)return t[id];
    int mid = (l+r)/2;
    node tmp1 = lay(id*2,l,mid,u,v);
    node tmp2 = lay(id*2+1,mid+1,r,u,v);
    return ghep(tmp1,tmp2);
}
void update(int id , int l , int r , int pos , int val)
{
    if(l == r)
    {
        arr[pos] = val;
        vector<ll> vtt = {val,t[id].ma1,t[id].ma2};
        sort(vtt.begin(),vtt.end(),greater<int>());
        t[id].ma1 = vtt[0];
        t[id].ma2 = vtt[1];
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    t[id] = ghep(t[id*2],t[id*2+1]);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)cin >> arr[i];
    build(1,1,n);
    //for(int i = 1 ; i <= 4*n ;i++)cout << t[i].ma1 << ' ' << t[i].ma2 <<el;
    cin >> m;
    while(m--)
    {
        cin >> op >> u >> v;
        if(op == 0)update(1,1,n,u,v);
        else
        {
            cin >> MOD;
            node ans = lay(1,1,n,u,v);
            if(u == v)cout << ans.ma1%MOD << el;
            else cout << mul(ans.ma1,ans.ma2,MOD) << el;
        }
    }
    return 0;
}
//freopen(".inp","v",stdin);freopen(".out","w",stdout);
