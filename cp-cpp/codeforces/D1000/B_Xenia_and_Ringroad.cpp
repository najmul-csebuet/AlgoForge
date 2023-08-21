#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pb push_back
#define eb emplace_back
#define fill(v, c) memset(v, c, sizeof(v))

#define var auto
#define endl "\n"
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

inline vector<int> nextInts(int n = 0) {
  if (n == 0) cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  return a;
}

void solve() {
  int n;
  cin >> n;
  vector<int> A = nextInts();
  int start = 1;
  long long count = 0;
  rep(i, 0, sz(A)) {
    if (A[i] >= start) {
      count += (A[i] - start);
    } else {
      int d = n - start + A[i];
      count += d;
    }
    start = A[i];
  }
  cout << count << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int testCount = 1;
  // testCount = io.nextInt();
  while (testCount > 0) {
    solve();
    --testCount;
  }
  return 0;
}