// Counts inversions in O(nlogn)

ll inversions(vector<int> &v){

  int n = (int)v.size();

  vector<int> temp(n);

  auto merge = [&](int l1, int r1, int l2, int r2){
    int idx_temp = l1;
    int ini = l1, end = r2;

    ll inversions = 0;

    while(l1 < r1 && l2 < r2){
      if(v[l1] <= v[l2]){
        temp[idx_temp++] = v[l1++];
      }
      else{
        inversions += r1-l1;
        temp[idx_temp++] = v[l2++];
      }
    }

    while(l1 < r1) temp[idx_temp++] = v[l1++];
    while(l2 < r2) temp[idx_temp++] = v[l2++];

    for(int i = ini; i < end; i++) v[i] = temp[i];

    return inversions;
  };

  function<ll(int, int)> cinv = [&](int l, int r){
    if(r-l == 1) return 0ll;

    int mid = (l + r)/2;

    ll left_inv = cinv(l, mid);
    ll right_inv = cinv(mid, r);
    ll mid_inv = merge(l, mid, mid, r);

    return left_inv + right_inv + mid_inv;
  };

  return cinv(0, n);
}
