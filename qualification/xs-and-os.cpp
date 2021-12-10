#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <utility>

#define MAXN 50
#define INF 0x3f3f3f3f

using namespace std;

string grid[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      getline(cin, grid[i]);
    }

    int best = INF, bestCnt = 0;
    set<pair<int, int>> holes;
    for(int flip = 0; flip <= 1; flip++) {
      for(int i = 0; i < n; i++) {
        int xs = 0, os = 0, spaceJ = -1;
        for(int j = 0; j < n; j++) {
          switch(flip ? grid[j][i] : grid[i][j]) {
            case '.': spaceJ = j; break;
            case 'O': os++; break;
            case 'X': xs++;
          }
        }
        if(os > 0) continue;

        pair<int, int> hole = {flip ? spaceJ : i, flip ? i : spaceJ};
        if(n - xs < best) {
          best = n - xs;
          bestCnt = 1;
          holes = {hole};
        } else if(n - xs == best) {
          bestCnt++;
          holes.insert(hole);
        }
      }
    }

    if(best == INF) {
      printf("Case #%d: Impossible\n", tc);
    } else {
      if(best == 1) bestCnt = holes.size();
      printf("Case #%d: %d %d\n", tc, best, bestCnt);
    }
  }
  return 0;
}
