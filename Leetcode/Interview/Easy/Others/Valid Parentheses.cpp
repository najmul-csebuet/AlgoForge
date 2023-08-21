#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
  bool matching(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') ||
           (c1 == '[' && c2 == ']');
  }

 public:
  bool isValid(string s) {
    stack<char> stk;
    tr(s, c) {
      if (stk.empty() || c == '(' || c == '{' || c == '[') {
        stk.push(c);
        continue;
      }
      if (matching(stk.top(), c)) {
        stk.pop();
      } else {
        return false;
      }
    }
    return stk.empty();
  }
};

int main() {
  var s = Solution();
  return 0;
}
