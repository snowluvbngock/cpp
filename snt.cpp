#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define el '\n'
#define fi first
#define se second
#define maxn 1000006
using namespace std;

int n,q;
vector<int> unt[maxn];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> q;
    for(int i = 2 ; i < maxn ; i++)if(unt[i].size() == 0)
    {
        for(int j = i ; j < maxn ; j+=i)
        {
            unt[j].pb(i);
        }
    }
    while(q--)
    {
        cin >> n;
        for(int x : unt[n])cout << x << ' ';
        cout << el;
    }
    return 0;
}
//freopen(".inp","r",stdin);freopen(".out","w",stdout);
