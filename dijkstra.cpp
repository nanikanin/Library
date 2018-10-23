#include <vector>
#include <queue>
using namespace std;

//From the Ant Book
template <typename T>
vector<T> dijkstra(vector<vector<pair<int, T>>> &G, int s){
  constexpr auto INF = numeric_limits<T>::max();
  using P = pair<T, int>;
  vector<T> dist(G.size(), INF);
  priority_queue<P, vector<P>, greater<P>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);

  while(!que.empty()){
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : G[idx]){
      auto next_cost = dist[idx] + e.second;
      if(dist[e.first] <= next_cost) continue;
      dist[e.first] = next_cost;
      que.emplace(dist[e.first], e.first);
    }
  }
  return dist;
}