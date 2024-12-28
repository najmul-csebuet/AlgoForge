#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// Constants
const ll MOD = 1e9 + 7;    // Common modulus
const ll INF = LLONG_MAX;  // Infinity
const ld EPS = 1e-9;       // Precision for floating-point comparison

// Shortcuts
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define F first
#define S second

// Debugging
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif

// Fast I/O
void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  bool use_files = false;
#ifdef LOCAL
  use_files = true;  // Automatically enable file I/O in local debugging
#endif
  if (use_files) {
    freopen("in.txt", "r", stdin);    // Redirect standard input to a file
    freopen("out.txt", "w", stdout);  // Redirect standard output to a file
  }
}

// Functions
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_exp(ll base, ll exp, ll mod) {
  ll res = 1;
  while (exp) {
    if (exp % 2) res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

void checkTests(const string &file1 = "ans.txt",
                const string &file2 = "out.txt") {
  ifstream f1(file1);
  ifstream f2(file2);

  if (!f1.is_open() || !f2.is_open()) {
    cerr << "Error: Could not open one or both files." << endl;
    return;
  }

  int line = 1;
  string line1, line2;
  while (getline(f1, line1) && getline(f2, line2)) {
    if (line1 == line2) continue;

    cerr << " #Test: " << line << ":" << '\n';
    cerr << "Answer: " << line1 << '\n';
    cerr << "output: " << line2 << '\n';
    return;  // Lines differ
  }

  cerr << "All tests passed." << endl << endl;
}

// Solve Function
void solve() {
  int a, b;
  cin >> a >> b;
  int ceil_div = ceil(double(a) / b);
  cout << ceil_div * b - a << endl;
}

int main() {
  fast_io();

  int t = 1;  // Default to 1 for single test case
  cin >> t;   // Uncomment if the number of test cases is given
  while (t--) solve();

#ifdef LOCAL
  cout.flush();
  checkTests();
#endif
  return 0;
}
