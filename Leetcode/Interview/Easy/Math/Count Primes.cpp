#include <bits/stdc++.h>
using namespace std;

#define var auto
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define sz(v) ((int)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define rep(i, a, b) for (var i = (a); i < (b); ++i)
#define tr(c, a) for (var & a : c)

// AC
class Solution {
 public:
  int countPrimes(int n) {
    vb primes(n, true);
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
      if (!primes[i]) continue;
      // so i is prime
      for (int j = i * i; j < n; j += i) {
        primes[j] = false;
      }
    }
    int count = 0;
    rep(i, 2, n) {
      if (primes[i]) ++count;
    }

    return count;
  }
};

int main() {
  var s = Solution();
  return 0;
}
