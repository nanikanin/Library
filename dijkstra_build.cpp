#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

template <typename T>
vector<vector<int>> dijkstra(vector<vector<pair<int, T>>> &g, int s){
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(g.size(), INF);
  vector<T> prev(g.size(), -1);
  using P = pair<T, int>;
  priority_queue<P, vector<P>, greater<P>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);

  while(!que.empty()){
    T cost; int idx;
    tie(cost, idx) = que.top(); que.pop();
    if(dist[idx]<cost) continue;
    for(int i=0; i<g[idx].size(); i++){
      P e = g[idx][i];
      auto next_cost = cost + e.second;
      if(dist[e.first] > next_cost){
        dist[e.first] = next_cost;
        prev[i] = idx;
        que.emplace(dist[e.first], e.first);
      }
    }
  }

  //get path
  vector<vector<int>> path(g.size());
  for(int i=0; i<g.size(); i++){
    for(int t=i; t!=-1; t=prev[t]) path[i].emplace_back(t);
    reverse(path[i].begin(), path[i].end());
  }
  return path;
}
