#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)

// AC
// class Solution {
//  public:
//   int maxProfit(vector<int> &prices) {
//     int lastLow = prices[0], lastHigh = prices[0], profit = 0;
//     rep(i, 1, sz(prices)) {
//       if (lastHigh > prices[i]) {
//         // sell
//         profit += (lastHigh - lastLow);
//         lastLow = lastHigh = prices[i];
//       } else {
//         lastHigh = prices[i];
//       }
//     }
//     // sell
//     profit += (lastHigh - lastLow);
//     return profit;
//   }
// };

class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int low = prices[0], high = prices[0], profit = 0;

    // for (int i = 1; i < prices.size(); i++) {
    //   if (high < prices[i]) {
    //     profit += (high - low);
    //     low = high = prices[i];
    //   } else {
    //     high = prices[i];
    //   }
    // }
    // return profit + (high - low);

    profit = 0;
    // prices = [7,1,5,3,6,4]
    for (int i = 1; i < prices.size(); i++) {
      if (high < prices[i]) {
        high = prices[i];
      }
      profit += max(0, high - low);
      low = high = prices[i];
    }
    return profit;
  }
};

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << (Solution().maxProfit(prices) == 7) << endl;

  prices = {7, 6, 4, 3, 1};
  cout << (Solution().maxProfit(prices) == 0) << endl;

  prices = {1, 2, 3, 4, 5};
  cout << (Solution().maxProfit(prices) == 4) << endl;
  return 0;
}
