#include <bits/stdc++.h>
using namespace std;

#define HIDE_TEMPLATE true
#ifdef HIDE_TEMPLATE

#define var auto
#define str string
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)
// #define tr(c, it) for (var it = c.begin(); it != c.end(); it++)

#define endl '\n'
#define eb emplace_back

#define eps (1e-9)
#define pie acos(-1)
#define ll long long
#define inf LLONG_MAX
#define eq(a, b) (abs(a - b) < eps)

#define mt make_tuple
#define mod(a, b) ((a % b + b) % b)
#define dist(x1, y1, x2, y2) sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))

#define si set<int>
#define pii pair<int, int>

#define fill(v, c) memset(v, c, sizeof(v))

#define rrep(i, a, b) for (auto i = (a)-1; i >= (b); --i)

#define trr(c, it) for (var it = c.rbegin(); it != c.rend(); it++)

#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

void err(istream_iterator<string> it) {}

template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }

void read() {}

template <class Arg, class... Rest>
void read(Arg &arg, Rest &...rest) {
  cin >> arg;
  read(rest...);
}

// https://codeforces.com/blog/entry/62393
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

#define umii unordered_map<int, int, custom_hash>
#define ghtii gp_hash_table<int, int, custom_hash>

#define boost(a)           \
  a.max_load_factor(0.25); \
  a.reserve(1 << 20);

#define class struct

class IO {
  IO() {
    // activate fast io
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  string next() {
    string str;
    cin >> str;
    return str;
  }

  int nextInt() {
    int n;
    cin >> n;
    return n;
  }

  template <typename T>
  T next() {
    T a;
    cin >> a;
    return a;
  }

  string nextLine() {
    string str;
    getline(cin, str);
    return str;
  }

  vi nextInts(int n = 0) {
    if (n == 0) cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    return a;
  }

  template <typename T>
  var nextItems(int n = 0) {
    if (n == 0) cin >> n;
    vector<T> a(n);
    rep(i, 0, n) cin >> a[i];
    return a;
  }

  void print(string message) { cout << message << endl; }

  void print(vi n, string separator = " ") {
    if (n.size() == 0) return;
    rep(i, 0, n.size() - 1) cout << n[i] << separator;
    cout << n[n.size() - 1] << endl;
  }
} io;

#endif

class Solution {
  int solve() {
    // solve here
    return 0;
  }
};

int main() {
  var testCount = 1;
  // testCount = io.nextInt();
  while (testCount > 0) {
    Solution().solve();
    --testCount;
  }

  return 0;
}