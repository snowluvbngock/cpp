#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define fi first
#define se second
#define maxn 500005
using namespace std;
int n,q,op,pos,l,r;
string a;
char val;
struct node
{
    map<char,int> ma;
    set<char> se;
}t[4*maxn];
node Merge(node a, node b)
{
    node kq;
    kq.se = b.se;
    for(int u : a.se)kq.se.insert(u);
    for(int u : kq.se)kq.ma[u] = a.ma[u] + b.ma[u];
    return kq;
}
set<char> ghep(set<char> &a , set<char> &b)
{
    set<char> kq = a;
    for(char u : b)kq.insert(u);
    return kq;
}
void build(int id , int l , int r)
{
    if(l == r)
    {
        t[id].ma[a[l]] = 1;
        t[id].se.insert(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id] = Merge(t[id*2], t[id*2+1]);
}
set<char> get(int id,int l, int r , int u , int v)
{
    if(v < l || r < u)return{};
    if(u <= l && r <= v)return t[id].se;
    int mid = (l+r)/2;
    set<char> temp1 = get(id*2,l,mid,u,v);
    set<char> temp2 = get(id*2 + 1,mid+1,r,u,v);
    return ghep(temp1,temp2);
}
void update(int id , int l , int r , int pos , char val)
{
    if(pos < l || r < pos)return;
    if(l == r)
    {
        t[id].ma[a[pos]]--;
        if(t[id].ma[a[pos]] == 0)t[id].se.erase(a[pos]);
        a[pos] = val;
        t[id].ma[a[pos]]++;
        t[id].se.insert(a[pos]);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    t[id] = Merge(t[id*2],t[id*2+1]);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> q;
    a = ' ' + a;
    build(1,1,n);
    while(q--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> pos >> val;
            update(1,1,n,pos,val);
        }
        else
        {
            cin >> l >> r;
            cout << get(1,1,n,l,r).size() << el;
        }
    }
    return 0;
}
//freopen(".inp","r",stdin);freopen(".out","w",stdout);
