#define left(x) 2*(x)+1
#define right(x) 2*(x)+2

struct sdata{
  int sum, pref, suff, ans;
};

const int MAXN = 3e5;
sdata seg[4*MAXN];

struct segtree{

  int n;
  segtree(vector<int> &v){
    n = (int)v.size();
    build(v);
  }


  sdata combine(sdata l, sdata r) {
      sdata res;
      res.sum = l.sum + r.sum;
      res.pref = max(l.pref, l.sum + r.pref);
      res.suff = max(r.suff, r.sum + l.suff);
      res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
      return res;
  }

  sdata make_data(int val) {
      sdata res;
      res.sum = val;
      res.pref = res.suff = res.ans = max(0, val);
      return res;
  }

  void build(int x, int lx, int rx, vector<int> &v){

    if(rx - lx == 0){
      seg[x] = make_data(v[lx]);
    }
    else{
      int mid = (lx+rx)/2;
      build(left(x), lx, mid, v);
      build(right(x), mid+1, rx, v);

      seg[x] = combine(seg[left(x)], seg[right(x)]);
    }
    
  }
  void build(vector<int> &v){
    build(0, 0, n-1, v);
  }

  //                                    l                 r
  //                      lx        rx
  //    
  sdata query(int x, int lx, int rx, int l, int r){

    if(lx >= l && rx <= r){
      return seg[x];
    }
    else if(lx > r || l > rx){
      return make_data(0);
    }
    else{
      int mid = (lx+rx)/2;
      return combine(query(left(x), lx, mid, l, r), query(right(x), mid+1, rx, l, r));
    }

  }
  sdata query(int l, int r){
    return query(0, 0, n-1, l, r);
  }
  
  void update(int x, int lx, int rx, int idx, int v){
    if(rx - lx == 0){
      seg[x] = make_data(v);
    }
    else{
      int mid = (lx + rx)/2;
      if(idx <= mid){
        update(left(x), lx, mid, idx, v);
      }
      else{
        update(right(x), mid+1, rx, idx , v);
      }

      seg[x] = combine(seg[left(x)], seg[right(x)]);
    }
  }

  void update(int idx, int v){
    return update(0, 0, n-1, idx, v);
  }
};

int main(){
  vector<int> v = {-1, 2, 3, 4, -5 ,6, 7, 8, 9, 10};
  segtree s(v);
  cout << s.query(0, 4).ans << '\n';
}
