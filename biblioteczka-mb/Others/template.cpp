#include <bits/stdc++.h>
//#include <bits/extc++.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////

#define upgrade ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define ll long long
#define f first
#define s second
//#define x first
//#define y second
#define pb push_back
#define mp make_pair
#define mt make_tuple

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, j, n, m) FOR(i, n) FOR(j, m)
#define CF int n; cin >> n; FOR(i, n) solve()

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define pll pair<ll , ll>
#define pli pair<ll ,int>
#define pil pair<int, ll>

const ll MOD = 1e9 + 7;

/*template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree <
    K, V, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>> using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;*/

template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {os << "{" << p.f << ", " << p.s << "}"; return os;}
template<typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) {T1 a; T2 b; is >> a >> b; p = {a, b}; return is;}
template<typename T1, typename T2, typename T3> ostream &operator<<(ostream &os, const tuple<T1,T2,T3> &t) {os << "{" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "}"; return os;}
template<typename T1, typename T2, typename T3> istream &operator>>(istream &is, tuple<T1,T2,T3> &t) {T1 a; T2 b; T3 c; is >> a >> b >> c; t = mt(a,b,c); return is;}

template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os << '['; FOR(i, sz(v)) {os << v[i]; if(i < sz(v)-1) os << ", ";} os << "]"; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }
//template <typename T> ostream &operator<<(ostream &os, const ordered_set<T> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x.f << ": " << x.s; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &v) { os << '['; int cnt = 0; for (auto x : v) {os << x.f << ": " << x.s; if(++cnt < sz(v)) os << ", ";} os << ']'; return os; }

template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &A, const pair<T1, T2> &B) {return {A.f + B.f, A.s + B.s};}
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &A, const pair<T1, T2> &B) {return {A.f - B.f, A.s - B.s};}
template<typename T1, typename T2> pair<T1, T2> operator/(const pair<T1, T2> &A, const pair<T1, T2> &B) {assert(B.s != 0 and B.f != 0); return {A.f / B.f, A.s / B.s};}
template<typename T1, typename T2> pair<T1, T2> operator*(const pair<T1, T2> &A, const pair<T1, T2> &B) {return {A.f * B.f, A.s * B.s};}

//template<typename T> T operator*(const pair<T, T> &A, const pair<T, T> &B) {return A.x * B.y - A.y * B.x;}
//template<typename T> T operator^(const pair<T, T> &A, const pair<T, T> &B) {return A.x * B.x + A.y * B.y;}

// https://codeforces.com/blog/entry/15643
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << ": " << a << "\n";
    err(++it, args...);
}
//

ll rand(ll a, ll b) {if(b < a)swap(a,b); return rand()%(b-a+1) + a;}
template<typename T> vector <T> generate(int n, int l, int r) {vector <T> v(n); for(auto &x: v) x = rand(l, r); return v;}
int lg_floor(int n) {return 32 - __builtin_clz(n-1);}
template<typename T> static void umax(T &a, T &b) {a = max(a,b);}
template<typename T> static void umin(T &a, T &b) {a = min(a,b);}

///////////////////////////////////////////////////////////////////////////////////////