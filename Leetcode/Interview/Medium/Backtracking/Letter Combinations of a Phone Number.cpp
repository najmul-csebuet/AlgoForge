#include <bits/stdc++.h>
using namespace std;

#define var auto
#define str string
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
  map<char, str> mp;
  void gen(int index, str digits, str s, vs& ans) {
    if (index == sz(digits)) {
      ans.pb(s);
      return;
    }
    str mapping = mp[digits[index]];
    rep(i, 0, sz(mapping)) {
      str temp = s;
      s += mapping[i];
      gen(index + 1, digits, s, ans);
      s = temp;
    }
  }

 public:
  vs letterCombinations(str digits) {
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    vs ans;
    if (digits.empty()) return ans;

    // "23"
    gen(0, digits, "", ans);

    return ans;
  }
};

void testCase1() {
  var s = Solution();
  var ans = s.letterCombinations("23");
  int a;
}

int main() {
  testCase1();
  return 0;
}
