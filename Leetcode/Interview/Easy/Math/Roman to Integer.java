package Leetcode.Interview.Easy.Math;

import java.util.HashMap;

class Solution_AC {

    public int romanToInt(String s) {
        int ans = 0;
        var map = new HashMap<String, Integer>();
        map.put("I", 1);
        map.put("V", 5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);

        for (int i = 0; i < s.length(); ++i) {
            char ch1 = s.charAt(i);
            if (ch1 == 'I') {
                if (i + 1 < s.length()) {
                    char ch2 = s.charAt(i + 1);
                    if (ch2 == 'V') {
                        ans += 4;
                        ++i;
                    } else if (ch2 == 'X') {
                        ans += 9;
                        ++i;
                    } else {
                        ans += 1;
                    }
                } else {
                    ans += 1;
                }
            }

            else if (ch1 == 'X') {
                if (i + 1 < s.length()) {
                    char ch2 = s.charAt(i + 1);
                    if (ch2 == 'L') {
                        ans += 40;
                        ++i;
                    } else if (ch2 == 'C') {
                        ans += 90;
                        ++i;
                    } else {
                        ans += 10;
                    }
                } else {
                    ans += 10;
                }
            }

            else if (ch1 == 'C') {
                if (i + 1 < s.length()) {
                    char ch2 = s.charAt(i + 1);
                    if (ch2 == 'D') {
                        ans += 400;
                        ++i;
                    } else if (ch2 == 'M') {
                        ans += 900;
                        ++i;
                    } else {
                        ans += 100;
                    }
                } else {
                    ans += 100;
                }
            } else {
                ans += map.get(ch1 + "");
            }
        }
        return ans;
    }
}

class Solution {

    public int romanToInt(String s) {

        var map = new HashMap<Character, Integer>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int ans = 0, prev = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            int num = map.get(s.charAt(i));
            if (num < prev) {
                ans -= num;
            } else {
                ans += num;
            }
            prev = num;
        }
        return ans;
    }
}