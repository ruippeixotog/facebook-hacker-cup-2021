#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

#define MOD 1000000007

using namespace std;

typedef long long ll;

struct mll {
  ll val;
  mll(ll v): val(v % MOD) {}

  inline mll operator+(const mll b) const { return val + b.val; }
  inline mll operator*(const mll b) const { return val * b.val; }
  inline mll operator-(const mll b) const { return val + MOD - b.val; }
};

string u;

struct State {
  char firstKey, lastKey;
  mll n, sum, addL, addR, flips, firstPos, lastPos;

  State(): firstKey(0), lastKey(0),
    n(0), sum(0), addL(0), addR(0), flips(0), firstPos(-1), lastPos(-1) {}

  void append(char key) {
    if(key != 'F') {
      if(!lastKey) {
        firstKey = key;
        firstPos = n;
      } else if(key != lastKey) {
        flips = flips + 1;
        addR = addR + lastPos + 1;
      }
      lastKey = key;
      lastPos = n;
    }
    addL = addL + flips;
    sum = sum + addR;
    n = n + 1;
  }

  void dup() {
    sum = sum * 2 + (addL + addR) * n;

    addR = addR * 2 + n * flips;
    addL = addL * 2 + n * flips;
    flips = flips * 2;

    if(firstKey != lastKey) {
      sum = sum + (lastPos + 1) * (n - firstPos);
      addR = addR + (lastPos + 1);
      addL = addL + (n - firstPos);
      flips = flips + 1;
    }
    lastPos = n + lastPos;
    n = n * 2;
  }
};

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int k; scanf("%d\n", &k);
    getline(cin, u);

    State st;
    for(int i = 0; i < k; i++) {
      if(u[i] == '.') st.dup();
      else st.append(u[i]);
    }
    printf("Case #%d: %lld\n", tc, st.sum.val);
  }
  return 0;
}
