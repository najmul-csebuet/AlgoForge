#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  Solution() { fast_io(); }

  void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    bool use_files = false;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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

  int solve() {
    // take and process input
    return 0;
  }
};

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) Solution().solve();

#ifdef LOCAL
  cout.flush();
  checkTests();
#endif
  return 0;
}