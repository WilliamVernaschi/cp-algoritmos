/*
    This code assumes you are multiplying two matrices that can be multiplied: (A nxp * B pxm)
    Matrix fexp assumes square matrices
*/

template<typename T>
struct matrix{
  vector<vector<T>> a;
  int n, m;
  //matrix() = default;

  matrix(int _n, int _m) : n(_n), m(_m){
    a.resize(n, vector<T>(m));
  }

  matrix<T> operator *(matrix<T> other){
    // assert(this->m == other.n);
  
    matrix<T> result(this->n, other.m);
    for(int i = 0; i < result.n; i++){
      for(int j = 0; j < result.m; j++){
        for(int k = 0; k < this->m; k++){
          //result.a[i][j] = (result.a[i][j] + a[i][k] * other.a[k][j]);
          result.a[i][j] = (result.a[i][j] + (a[i][k] * other.a[k][j]) % MOD) % MOD;
        }
      }
    }
    return result;
  }
};

matrix<ll> ident(int n){
  matrix<ll> id(n, n);
  for(int i = 0; i < n; i++) id.a[i][i] = 1;
  return id;
}

template<typename T>
matrix<T> fexp(matrix<T> b, ll e){
  matrix<T> ans = ident(b.n);
  while(e){
    if(e & 1) ans = (ans * b);
    b = b * b;
    e >>= 1;
  }
  return ans;
}
