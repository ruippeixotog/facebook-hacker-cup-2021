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
        int val =
          i == 0 ? a - n - m + 2 :
          i == n - 1 ? b - n - m + 2 :
          1;
        printf("%d", val);
        for(int j = 1; j < m; j++) {
          printf(" 1");
        }
        printf("\n");
      }
    }
  }
  return 0;
}
