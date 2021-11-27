#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

string s;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int m; scanf("%d\n", &m);
    getline(cin, s);

    ll sum = 0;
    int last = -1;
    for(int i = 0; i < m; i++) {
      if(s[i] == 'F') continue;
      if(last != -1 && s[last] != s[i]) {
        sum = madd(sum, mmul(last + 1, m - i));
      }
      last = i;
    }
    printf("Case #%d: %lld\n", tc, sum);
  }
  return 0;
}
