#include <cstdio>

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m, a, b; scanf("%d %d %d %d\n", &n, &m, &a, &b);

    if(a < n + m - 1 || b < n + m - 1) {
      printf("Case #%d: Impossible\n", tc);
    } else {
      printf("Case #%d: Possible\n", tc);
      for(int i = 0; i < n; i++) {
        printf("1");
        for(int j = 1; j < m; j++) {
          int val =
            i == 0 ? (j == m - 1 ? b - n - m + 2 : 1) :
            i == n - 1 ? (j == m - 1 ? a - n - m + 2 : 1) :
            1000;
          printf(" %d", val);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
