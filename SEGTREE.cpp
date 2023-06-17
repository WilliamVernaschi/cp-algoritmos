// Segment Tree
/*
EXAMPLE USAGE:

int main(){
  int n, m; cin >> n >> m;
  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  segtree seg(v);

  while(m--){
    int a, b, c; cin >> a >> b >> c;
    if(a == 1){
      seg.update(b, c);
    }
    else{
      cout << seg.query(b, c) << '\n';
    }
  }
}

*/

struct segtree{

  vector<int> seg;
  int n;
  const int NEUTRAL = INF;

  segtree(int _n) : seg(4*_n) {
    n = _n;
  };
  segtree(vector<int> &v) : seg(4*(int)v.size(), NEUTRAL) {
    n = (int)v.size();
    build(v);

  };

  void build(vector<int> &v, int node, int l, int r){
    if(r-l == 1){
      seg[node] = v[l];
      return;
    }
    int mid = (l+r)/2;
    build(v, left(node), l, mid);
    build(v, right(node), mid, r);

    seg[node] = min(seg[left(node)] , seg[right(node)]);
  }

  void build(vector<int> &v){
    build(v, 0, 0, n);
  }

  int query(int l, int r, int node, int nl, int nr){
    if(l <= nl && r >= nr){
      return seg[node];
    }
    else if(nl >= r || nr <= l){
      return NEUTRAL;
    }
    else{
      int mid = (nl+nr)/2;
      return min(query(l, r, left(node), nl, mid),
        query(l, r, right(node), mid, nr));
    }
  }
  int query(int l, int r){
    return query(l, r, 0, 0, n);
  }
  void update(int i, int v, int node, int l, int r){
    if(r-l == 1){
      seg[node] = v;
    }
    else{
      int mid = (l+r)/2;
      if(i < mid)
        update(i, v, left(node), l, mid);
      else
        update(i, v, right(node), mid, r);
      

      seg[node] = min(seg[left(node)] , seg[right(node)]);
    }
  }
  void update(int i, int v){
    update(i, v, 0, 0, n);
  }
};

