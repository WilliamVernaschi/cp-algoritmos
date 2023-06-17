/*
   Fenwick Tree / Binary Indexed Tree

   Point Update & Range Query:
   Point Update = b.set(i, v)
   Range Query  = b.get(r) - b.get(l-1)
    
   Range Update & Point Query:
   Range Update = b.set(l, v) - b.set(r+1, -v)
   Point Query  = b.get(i)
*/
/*
EXAMPLE USAGE:

int main(){
  int n, q; cin >> n >> q;
  BIT<int> bit(n);
  while(q--){
    int t; cin >> t;
    if(t == 0){ // point update
      int i, val; cin >> i >> val;
      bit.set(i, val);
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
  int n;

  BIT(int n) : bit(n+1){
    this->n = n;
  };

  void set(int idx, T v){
    for(int i = idx; i <= n; i += i & -i) bit[i] += v;
  }

  T get(int idx){
    ll v = 0;
    for(int i = idx; i ; i -= i & -i) v += bit[i];
    return v;
  }

  T get(int l, int r){
    return get(r) - get(l-1);
  }

  /*
  T lower_bound(T val){
    int ans = 0, sum = 0;
    for(int i = M - 1; i >= 0; i--){
      int x = ans + (1 << i);
      if(sum + bit[x] < val) 
        ans = x, sum += bit[x];
    }

    return ans + 1;
  }
  */
};
