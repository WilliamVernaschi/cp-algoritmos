// Binary Indexed Tree / Fenwick Tree
// that allows range operations
//
/*
EXAMPLE USAGE:

int main(){
  BITRange<int> bit;
  int q; cin >> q;
  while(q--){
    int t; cin >> t;
    if(t == 0){ // range update
      int l, r, val; cin >> l >> r >> val;

      bit.set(l, r, val);
    }
    else if(t == 1){ // range query
      cout << bit.get(l, r) << '\n';
    }
  }
}
*/
template<class T>
struct BIT{

  vector<T> bit;

  BIT(int n) : bit(n+1){};

  void set(int idx, T v){
    for(int i = idx; i <= n; i += i & -i) bit[i] += v;
  }

  T get(int idx){
    ll v = 0;
    for(int i = idx; i ; i -= i & -i) v += bit[i];
    return v;
  }
};

// allows Range Update & Range Query.
template<typename T>
struct BITRange{
  BIT<T> a, b;

  BITRange(int n) : a(n), b(n){};
  
  void set(int l, int r, ll v){
    a.set(l, v);
    a.set(r+1, -v);
    b.set(l, v*(l-1));
    b.set(r+1, -v*r);
  }

  ll get(int idx){
    return idx*a.get(idx) - b.get(idx);
  }

  ll get(int l, int r){
    return get(r) - get(l-1);
  }
};
