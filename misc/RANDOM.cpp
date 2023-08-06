int main(){
  FFIO;

  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  // mt19937_64 for 64 bit random numbers

  vector<int> v(10);
  for(int i = 0; i < 10; i++){
    v[i] = i;
  }
  shuffle(v.begin(), v.end(), rng);

  cout << (uniform_int_distribution<int>(0, 100)(rng)) << '\n';
  cout << (normal_distribution<double>(0, 100)(rng)) << '\n';
}

