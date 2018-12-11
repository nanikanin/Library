#include <vector>
using namespace std;

template <typename T>
struct Edge {
  int from, to;
  T cost;
};

template <typename T>
vector<T> bellman_ford(vector<Edge<T>> &E, int V, int s) {
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(V, INF);
  dist[s] = 0;
  while (true) {
    bool update = false;
    for (auto &e : E) {
      if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
  return dist;
}

//目的地が決まっていないときの閉路判定
template <typename T>
bool find_negative_loop(vector<Edge<T>> &E, int V) {
  vector<T> dist(V, 0);
  for(int i=0; i<v; i++) {
    for(auto &e : E) {
      if(dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        if (i == V - 1) return true;
      }
    }
  }
  return false;
}

//始点と目的地が決まっている場合の閉路判定
template <typename T>
bool find_negative_loop(vector<Edge<T>> &E, int V, int s, int t) {
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(V, INF);
  dist[s] = 0;
  for(int i=0; i<2*V; i++) {
    for(auto &e : E) {
      if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        if(i>=V-1 && e.to==t) return true;
      }
    }
  }
  return false;
}