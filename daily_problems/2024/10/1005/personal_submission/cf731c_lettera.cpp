#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), l(m), r(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
        g[l[i]].push_back(r[i]);
        g[r[i]].push_back(l[i]);
    }
    vector<int> vis(n);
    map<int, int> mp;
    int cnt=0;
    auto dfs = [&](auto self, int u) -> void {
        vis[u] = 1;
        mp[a[u]]++;
        cnt++;
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                self(self, v);
            }
        }
    };
    int ans=0;
    for (int i = 0; i < n; i++)
    {
    	if(!vis[i])
    	{
    		mp.clear();
    		cnt=0;
    		dfs(dfs,i);
    		int res=0;
    		for(auto [x,y]:mp)
    		{
    			res=max(res,y);
    		}
    		ans+=cnt-res;
    	}
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
