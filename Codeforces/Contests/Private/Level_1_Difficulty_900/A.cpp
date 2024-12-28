#include <bits/stdc++.h>

using namespace std;

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

void checkTests(const string &file1, const string &file2) {
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

  cerr << "All test cases passed." << endl << endl;
}

class Solution {
 public:
  void solve() {
    int a, n, best = 0;
    vector<int> sushi;
    cin >> n;

    while (n-- > 0) {
      cin >> a;
      sushi.push_back(a);
    }

    for (int i = 1; i < sushi.size(); ++i) {
      if (sushi[i - 1] == sushi[i]) {
        continue;
      }
      int current = 0;
      int left = i - 1, right = i, original = sushi[i];
      while (0 <= left && right < sushi.size() && sushi[left] != sushi[right] &&
             sushi[right] == original) {
        current += 2;
        --left;
        ++right;
      }
      best = max(best, current);
    }

    cout << best << '\n';
  }
};

int main() {
  fast_io();

  int t = 1;  // Default to 1 for single test case
  cin >> t;   // Uncomment if the number of test cases is given
  while (t--) Solution().solve();

#ifdef LOCAL
  cout.flush();
  areFilesIdentical("ans.txt", "out.txt");
#endif

  return 0;
}