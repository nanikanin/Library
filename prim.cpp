#include <vector>
#include <queue>
using namespace std;

template <typename T>
int prim(vector<vector<pair<int, T>>> &g){
  using P = pair<T, int>;

  int res = 0;
  vector<bool> used(g.size(), false);
  priority_queue<P, vector<P>, greater<P>> que;
  que.emplace(0, 0);
  while(!que.empty()){
    P p = que.top();
    que.pop();
    if(used[p.second]) continue;
    used[p.second] = true;
    res += p.first;
    for(auto &e : g[p.second]){
      que.emplace(e.second, e.first);
    }
  }
  return res;
}