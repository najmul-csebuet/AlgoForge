#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
#define pb push_back
#define vi vector<int>
#define vs vector<str>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
  int leftBraceCount;
  int rightBraceCount;
  void dfs(vs& ans, string exp, int balance, int index, int slotCount) {
    if (balance < 0) {
      return;
    }

    if (balance == 0 && exp.size() == slotCount) {
      ans.pb(exp);
      return;
    }

    if (leftBraceCount) {
      --leftBraceCount;
      dfs(ans, exp + '(', balance + 1, index + 1, slotCount);
      ++leftBraceCount;
    }

    if (rightBraceCount) {
      --rightBraceCount;
      dfs(ans, exp + ')', balance - 1, index + 1, slotCount);
      ++rightBraceCount;
    }
  }

 public:
  vs generateParenthesis(int n) {
    // n = 3
    // ()()()
    // ()(())
    int balance = 0;
    // ( will inc balance
    // ) will dec balance
    // if balance = 0, we will add the expression to ans;
    vs ans;
    leftBraceCount = rightBraceCount = n;
    dfs(ans, "", 0, 0, 2 * n);
    return ans;
  }
};

void testCase1() {
  var s = Solution();
  var ans = s.generateParenthesis(1);
}

int main() {
  testCase1();
  return 0;
}
