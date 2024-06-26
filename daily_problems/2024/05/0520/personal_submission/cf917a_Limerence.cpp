/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: zhengyi20thu
 * Time: 2024-05-20 11:34:33
 **/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n, false));
    vector<vector<bool>> g(n, vector<bool>(n, false));

    for (int l = 0; l < n; ++l)
    {
        bool res = true;
        int cnt = 0;
        for (int r = l; r < n; ++r)
        {
            if (s[r] == ')')
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
            if (cnt < 0)
            {
                res = false;
            }
            f[l][r] = res;
        }
    }

    for (int r = 0; r < n; ++r)
    {
        bool res = true;
        int cnt = 0;
        for (int l = r; l >= 0; --l)
        {
            if (s[l] == '(')
            {
                cnt--;
            }
            else
            {
                cnt++;
            }
            if (cnt < 0)
            {
                res = false;
            }
            g[l][r] = res;
        }
    }

    int ans = 0;
    for (int l = 0; l < n; ++l)
    {
        for (int r = l; r < n; ++r)
        {
            if (f[l][r] && g[l][r] && (r - l + 1) % 2 == 0)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
