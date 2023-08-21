#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define mis map<int, string>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

// 4th AC
class Solution {
 public:
  vs fizzBuzz(int n) {
    vs ans(n);

    vi divs = {3, 5};
    mis mp = {{3, "Fizz"}, {5, "Buzz"}};
    // vs values = {"Fizz", "Buzz"};
    // rep(i, 0, sz(divs)) { mp[divs[i]] = values[i]; }

    rep(i, 1, n + 1) {
      bool f = true;
      tr(divs, d) {
        if (i % d == 0) {
          ans[i - 1] += mp[d];
          f = false;
        }
      }
      if (f) ans[i - 1] = to_string(i);
    }
    return ans;
  }
};

class Solution_AC_3 {
 public:
  vs fizzBuzz(int n) {
    vs ans(n);
    rep(i, 1, n + 1) {
      if (i % 3 == 0) ans[i - 1] = "Fizz";
      if (i % 5 == 0) ans[i - 1] += "Buzz";
      if (i % 3 != 0 && i % 5 != 0) ans[i - 1] = to_string(i);
    }
    return ans;
  }
};

class Solution_AC_2 {
 public:
  vs fizzBuzz(int n) {
    vs ans(n);

    for (int i = 1; i <= n; i++) {
      ans[i - 1] = to_string(i);
    }

    for (int i = 3; i <= n; i += 3) {
      ans[i - 1] = "Fizz";
    }

    for (int i = 5; i <= n; i += 5) {
      ans[i - 1] = "Buzz";
    }

    for (int i = 15; i <= n; i += 15) {
      ans[i - 1] = "FizzBuzz";
    }

    return ans;
  }
};

class Solution_AC_1 {
 public:
  vs fizzBuzz(int n) {
    vs ans;
    rep(i, 1, n + 1) {
      if (i % 15 == 0) {
        ans.pb("FizzBuzz");
      } else if (i % 3 == 0) {
        ans.pb("Fizz");
      } else if (i % 5 == 0) {
        ans.pb("Buzz");
      } else {
        ans.pb(to_string(i));
      }
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  return 0;
}
