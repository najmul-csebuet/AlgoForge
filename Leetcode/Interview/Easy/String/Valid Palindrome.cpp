#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution {
 public:
  bool isPalindrome(string s) {
    vc s1, s2;
    tr(s, a) {
      char c = tolower(a);
      if (isalnum(c)) {
        s1.pb(c);
        s2.pb(c);
      }
    }
    reverse(all(s2));
    return s1 == s2;
  }
};

int main() {
  var s = Solution();
  var res = s.isPalindrome("A man, a plan, a canal: Panama");
  return 0;
}
