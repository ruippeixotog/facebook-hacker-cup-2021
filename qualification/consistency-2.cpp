#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define INF 100000

using namespace std;

map<char, vector<char>> repl;

int bfsFind(char st, char tgt) {
  set<char> visited;
  queue<pair<char, int>> q;
  q.emplace(st, 0);

  while(!q.empty()) {
    char curr; int depth;
    tie(curr, depth) = q.front(); q.pop();
    if(curr == tgt) return depth;
    
    for(int adj : repl[curr]) {
      if(!visited.count(adj)) {
        visited.insert(adj);
        q.emplace(adj, depth + 1);
      }
    }
  }
  return INF;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string s; getline(cin, s);

    repl.clear();
    int k; scanf("%d\n", &k);
    for(int i = 0; i < k; i++) {
      string ab; getline(cin, ab);
      repl[ab[0]].push_back(ab[1]);
    }

    int best = INF;
    for(char tgt = 'A'; tgt <= 'Z'; tgt++) {
      int cost = 0;
      for(char ch : s) {
        cost += bfsFind(ch, tgt);
      }
      best = min(best, cost);
    }
    printf("Case #%d: %d\n", tc, best == INF ? -1 : best);
  }
  return 0;
}
