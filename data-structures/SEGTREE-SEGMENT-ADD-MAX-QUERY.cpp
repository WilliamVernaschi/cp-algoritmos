
struct segtree{
  int n; 

  segtree(int _n){
    n = _n;
  }

  void build(int a[], int v, int tl, int tr) {
      if (tl == tr) {
          seg[v] = a[tl];
      } else {
          int tm = (tl + tr) / 2;
          build(a, LEFT(v), tl, tm);
          build(a, RIGHT(v), tm+1, tr);
          seg[v] = max(seg[left(x)], seg[right(x)]);
      }
  }
  void push(int v) {
      seg[LEFT(v)] += lazy[v];
      lazy[LEFT(v)] += lazy[v];
      seg[RIGHT(v)] += lazy[v];
      lazy[RIGHT(v)] += lazy[v];
      lazy[v] = 0;
  }

  void update(int v, int lx, int rx, int l, int r, int addend) {
      if (lx >= l && rx <= r){
          seg[v] += addend;
          lazy[v] += addend;
      }
      else if (lx > r || l > rx){
        return;
      }
      else{
          push(v);
          int tm = (tl + tr) / 2;
          update(LEFT(v), tl, tm, l, r, addend);
          update(RIGHT(v), tm+1, tr, l, r, addend);
          seg[v] = max(seg[LEFT(v)], seg[RIGHT(v)]);
      }
  }

  void update(int l, int r, int v){
    update(0, 0, n-1, l, r, v);
  }

  // l              r
  //   lx       rx
  int query(int v, int tl, int tr, int l, int r) {
      if (lx >= l && rx <= r)
          return seg[v];
      if (lx > r || l > rx)
          return -INF;
      push(v);
      int tm = (tl + tr) / 2;
      return max(query(LEFT(v), tl, tm, l, r), 
                 query(RIGHT(v), tm+1, tr, l, r));
  }

  int query(int l, int r){
    return query(0, 0, n-1, l, r);
  }

};
