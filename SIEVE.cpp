/*
EXAMPLE USAGE:
int main(){
  sieve();
  cout << is_prime[1e8+7] << '\n'; // true
}
  
*/

const int MAXN = 1e8+8;

vector<bool> is_prime(MAXN+2, true);
//vector<int> least_div(n+1); 


void sieve(){
  is_prime[0] = is_prime[1] = false;
  for(int i = 4; i <= MAXN; i+=2) is_prime[i] = false;

  for (int i = 3; i <= MAXN; i+=2) {
    is_prime[i+1] = false;
    if (is_prime[i] && (ll)i * i <= n) {

      // comment this for loop and uncomment bellow to 
      // get the smallest prime divisor of every
      // number from 1 to n
      for (int j = (ll)i*i; j <= MAXN; j += i){
        is_prime[j] = false;
      }
      /*
      for (int j = i; j <= MAXN; j += i){
        is_prime[j] = false;
        least_div[j] = i;
      }
      */
        
    }
  }
}
