#include <vector>
using namespace std;

template <typename T = int>
void warshall_floyd(vector<vector<T>> &g){
  for(int k = 0; k < g.size(); k++){
    for(int i = 0; i < g.size(); i++){
      for(int j = 0; j < g.size(); j++){
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
}