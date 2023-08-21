#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

class MinStack {
  vii st;

 public:
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.pb({val, val});
    } else {
      st.pb({val, min(val, st.back().second)});
    }
  }

  void pop() {
    st.pop_back();
  }

  int top() {
    return st.back().first;
  }

  int getMin() {
    return st.back().second;
  }
};

int main() {
  // var s = Solution();
  return 0;
}
