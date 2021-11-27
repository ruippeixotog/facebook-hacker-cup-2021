#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string h;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    getline(cin, h);

    int score1 = 0, score2 = 0;
    bool isLeft1 = false, isLeft2 = true;
    for(int i = 0; i < n; i++) {
      if(h[i] == 'X' && isLeft1) { score1++; isLeft1 = false; }
      if(h[i] == 'O' && !isLeft1) { score1++; isLeft1 = true; }
      if(h[i] == 'X' && isLeft2) { score2++; isLeft2 = false; }
      if(h[i] == 'O' && !isLeft2) { score2++; isLeft2 = true; }
    }
    printf("Case #%d: %d\n", tc, min(score1, score2));
  }
  return 0;
}
