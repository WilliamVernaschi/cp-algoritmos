const int MOD = 1e9+7;
const int p = 31; 

vector<int> rabin_karp(string const& s, string const& t) {

  int S = s.size(), T = t.size();

  vector<long long> p_pow(max(S, T)); 

  p_pow[0] = 1; 
  for(int i = 1; i < (int)p_pow.size(); i++) 
    p_pow[i] = (p_pow[i-1] * p) % MOD;

  vector<long long> h_pfx(T + 1, 0); 

  for (int i = 0; i < T; i++)
    h_pfx[i+1] = (h_pfx[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD; 

  long long h_s = 0; 
  for (int i = 0; i < S; i++) 
    h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % MOD; 

  vector<int> occurences;

  for (int i = 0; i + S - 1 < T; i++) { 
    long long cur_h = (h_pfx[i+S] + MOD - h_pfx[i]) % MOD; 
    if (cur_h == h_s * p_pow[i] % MOD)
      occurences.push_back(i);
  }

  return occurences;
}
