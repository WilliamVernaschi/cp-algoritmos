/**
 * Description: Modular arithmetic. Assumes $MOD$ is prime.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; inv(a); // 400000003
 */

template<int MOD> struct mint {
 	int v; 
 	explicit operator int() const { return v; } 
	mint():v(0) {}
	mint(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
	mint& operator+=(mint o) {
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; 
  }
	mint& operator-=(mint o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; 
  }
	mint& operator*=(mint o){ 
		v = int((ll)v*o.v%MOD); return *this; 
  }
	friend mint pow(mint a, ll p) { assert(p >= 0);
		return p==0?1:pow(a*a,p/2)*(p&1?a:1); 
  }
	friend mint inv(mint a){
    assert(a.v != 0); return pow(a,MOD-2); 
  }
	friend mint operator+(mint a, mint b){
    return a += b; 
  }
	friend mint operator-(mint a, mint b){
    return a -= b; 
  }
	friend mint operator*(mint a, mint b){
    return a *= b; 
  }
};

ostream &operator<<(ostream &os, mint<MOD> const &m){ 
    return os << m.v;
}

using mi = mint<MOD>;

const int MAXN = 1e7+5;
vector<mi> facmod(MAXN);

void makefac(){
  facmod[0] = 1;
  for(int i = 0; i <= MAXN; i++) facmod[i] *= facmod[i-1]*i;
}

