// Fenwick Tree 2D / Binary Indexed Tree 2D
// status: tested

// consider replacing the bit vector<vector<>> with a static 
// matrix to make it faster.
template<typename T>
struct BIT2D{

  vector<vector<T>> bit;
  int n, m;

  BIT2D(int n, int m){
    bit.assign(n+1, vector<T>(m+1, 0));
    this->n = n;
    this->m = m;
  }

  T get(int x, int y){
    ll v = 0;
    for(int i = x; i ; i -= i & -i) for(int j = y; j ; j -= j & -j)
        v += bit[i][j];
    return v;
  }

  T get(int x1, int y1, int x0, int y0){
    int x11=max(x1, x0);
    int y11=max(y1, y0);
    int x00=min(x1, x0);
    int y00=min(y1, y0);

    x1 = x11, y1 = y11, x0 = x00, y0 = y00;


    return get(x1, y1) - get(x1, y0-1) - get(x0-1, y1) + get(x0-1, y0-1);
  }


  void set(int x, int y, T v){
    for(int i = x; i <= n; i += i & -i) for(int j = y; j <= m; j += j & -j)
        bit[i][j] += v;
  }

};
