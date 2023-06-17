// sqrt decomposition
// process range queries in in O(n*sqrt(n))

// consider using a constant block size
// const int B = 900

struct query{
  int l, int r;
};

vector<int> sqrt_decomp(vector<query> &queries, vector<int> &a){
  // preprocessing
  int n = a.size();

  int B = sqrt(n) + 1;
  vector<int> b(B);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    b[i/B] += a[i];
  }

  // queries
  for(int q : queries){
    int l = q.l, r = q.r;

    int lb = l/B, rb = r/B;
    int ans = 0;

    if(lb == rb){
      for(int i = l; i <= r; i++) ans += a[i];
    }
    else{
      for(int i = l, end = (lb+1)*B-1; i <= end; i++)
        ans += a[i];
      
      for(int i = lb+1; i <= rb-1; i++)
        ans += b[i];
      
      for(int i = rb*B; i <= r; i++)
        ans += a[i];
    }
    
    cout << ans << '\n';
  }

}
