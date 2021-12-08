#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

#define INF 100000

using namespace std;

inline bool isVowel(char ch) {
  return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; getline(cin, s);

    int best = INF;
    for(char tgt = 'A'; tgt <= 'Z'; tgt++) {
      int cost = 0;
      for(char ch : s) {
        if(ch == tgt) continue;
        cost += isVowel(ch) == isVowel(tgt) ? 2 : 1; 
      }
      best = min(best, cost);
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
