#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vsi vector<pair<string, int>>
#define vs vector<string>
#define vvi vector<vi>
#define vvs vector<vs>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define umsvs unordered_map<string, vs>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class Solution_AC_33_ms {
 public:
  vvs groupAnagrams(vs& strs) {
    vvs ans;
    umsvs map;
    tr(strs, s) {
      string t = s;
      sort(all(t));
      map[t].pb(s);
    }
    tr(map, item) { ans.pb(move(item.second)); }
    return ans;
  }
};

class Solution_AC_32_ms {
 public:
  vvs groupAnagrams(vs& strs) {
    vsi temp;
    rep(i, 0, sz(strs)) {
      string s = strs[i];
      sort(all(s));
      temp.pb({s, i});
    }

    sort(all(temp));
    // dummy
    temp.pb({"$$$", -1});

    vvs ans;
    vs t;
    rep(i, 0, sz(temp) - 1) {
      t.pb(strs[temp[i].second]);
      if (temp[i].first != temp[i + 1].first) {
        ans.pb(t);
        t.clear();
      }
    }
    return ans;
  }
};

int main() {
  var s = Solution();
  vs t = {"eat", "tea", "tan", "ate", "nat", "bat"};
  var ans = s.groupAnagrams(t);
  return 0;
}
