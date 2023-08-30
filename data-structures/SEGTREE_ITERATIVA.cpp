#include <bits/stdc++.h>

using namespace std;

const int N = 1e5; // max array size
int seg[2 * N];

struct segtree{

  int n;
  segtree(int n_){
    n = n_;
  }

  segtree(vector<int> &v){
    n = (int)v.size();
    build(v);
  }

  int combine(int a, int b){
    return a+b;
  }

  void update(int idx, int v){
    for(seg[idx += n] = v; idx > 1; idx>>=1)
      seg[idx>>1] = seg[idx] + seg[idx^1];
  }


  int query(int l, int r){
    l += n, r += n+1;

    int resl = 0, resr=0;
    while(l < r){
      if(l&1) resl = combine(resl, seg[l++]);
      if(r&1) resr = combine(seg[--r], resr);

      l >>= 1, r >>= 1;
    }
    return combine(resl, resr);
  }

  void build(vector<int> &v){

    for(int i = 0; i < n; i++){
      seg[n+i] = v[i];
    }

    for(int i = n-1; i > 0; i--)
      seg[i] = seg[i<<1] + seg[i<<1|1];
  }
};


/*
int main(){
  FFIO;
  int n; cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  segtree s(v);
  int q; cin >> q;
  while(q--){
    int t; cin >> t;
    if(t == 1){
      int i, x; cin >> i >> x;
      i--;
      s.update(i, x);
    }
    else{
      int l, r; cin >> l >> r;
      l--, r--;
      cout << s.query(l, r) << '\n';
    }
  }
}
*/

