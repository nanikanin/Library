#include <vector>
using namespace std;

//RMQ
template <typename T>
class SegmentTree {
  public:
    SegmentTree(vector<int> v){
      int size = v.size();
      while(N < size) n *= 2;
      node.resize(2*N-1, INF);

      for(int i = 0; i < size; i++){
        node[i+n-1] = v[i];
      }
      for(int i = n - 2; i >= 0; i--){
        node[i] = min(node[2*i+1], node[2*i+2]);
      }
    }
    void update(int x, int val){
      x += (N-1);
      node[x] = val;
      while(x > 0){
        x = (x - 1) / 2;
        node[x] = min(node[2*x+1], node[2*x+2]);
      }
    }
    int getmin(int a, int b, int k=0, int l=0, int r=-1){
      if(r < 0) r = N;
      if(r <= a || b <= l) return INF;
      if(a <= l && r <= b) return node[k];

      int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
      int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
      return min(vl, vr);
    }
  private:
    int N = 1;
    vector<int> node;
};

/*
性質
・元のデータの数をn個とするときn以上となる最小の2冪の数をNとする
このときノードは全部で2N-1個となる

・また、上から順に0,1...のように番号を振っていくと、自分のノードの番号をkとするとき、
  parent -> children: 2k + 1 | 2k + 2
  children -> parent: floor((k-1)/2)
*/