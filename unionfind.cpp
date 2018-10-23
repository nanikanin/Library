#include <vector>
using namespace std;

class union_find {
  public:
    union_find(size_t size){
      rank.resize(size);
      for(int i=0; i<size; i++){
        parent.push_back(i);
      }
    }

    int find(int x){
      if (parent[x] == x){
        return x;
      }
      else{
        return parent[x] = find(parent[x]);
      }
    }

    void unite(int x, int y) {
      x = find(x);
      y = find(y);
      if(x == y) return;
      if(rank[x] < rank[y]){
        parent[x] = y;
      }
      else{
        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
      }
    }

    bool same(int x, int y){
      return find(x) == find(y);
    }
  
  private:
    vector<int> parent;
    vector<int> rank;
};