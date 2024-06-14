#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define cn cout << "\n"
#define CY cout << "YES\n"
#define CN cout << "NO\n"
#define ca cout << ans << "\n"
#define fo(i, x, y) for (int i = x; i < y; ++i)
#define len(x) ll(x.size())
#define all(x) x.begin(), x.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define IOS ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
template <class T>
using tp3 = tuple<T, T, T>;
template <class T>
using tp4 = tuple<T, T, T, T>;
#define vv(type, name, h, ...) \
    vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
struct node
{
    int x, y, z;
    // bool operator>(const node &a) const { return x > a.x; }//小根堆
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int popcnt(int x) { return __builtin_popcount(x); } // 二进制位为 1 的数量
int popcnt(ll x) { return __builtin_popcountll(x); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
// __builtin_clz(x)求x的二进制数前导0的个数(一共有32位), Count Leading Zeros
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
//__builtin_ctz(x)求x的二进制数末尾0的个数,Count  Trailing Zeros
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
inline ll gi() // 注意与cin,cout混用时打开流同步
{
    ll s = 0, f = 1;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * f;
}
const int mod = 1 ? 998244353 : 1e9 + 7;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define LOCAL
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 2024
#endif
void solve()
{
    // n==1
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    fo(i, 0, n)
    {
        if (a[i] == '1')
        {
            cnt1++;
        }
        if (b[i] == '1')
            cnt2++;
    }
    int ans = n + 3;
    if (cnt1 == cnt2)
    {
        int res = 0;
        fo(i, 0, n)
        {
            if (a[i] != b[i])
            {
                res++;
            }
        }
        ans = min(ans, res);
    }
    if (cnt2 == n - cnt1 + 1)
    {
        int res = 0, f = 0;
        fo(i, 0, n)
        {
            if (a[i] == b[i])
            {
                res++;
                f |= (a[i] == '1');
            }
        }
        ans = min(ans, res + 2 - f * 2);
    }
    cout << (ans == n + 3 ? -1 : ans) << "\n";
}
int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
