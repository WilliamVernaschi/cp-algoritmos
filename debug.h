#include <bits/stdc++.h>

using namespace std;

template<typename T>
concept _p = requires { typename T::first_type; };

template<typename T>
void __print(const T& x);

template <typename T, typename V>
void __print(const pair<T, V>& x){
  __print('{'),
  __print(x.first),
  __print(','),
  __print(x.second),
  __print('}');
}

template<typename T>
void __print(const T& x){
  if constexpr (ranges::range<T> && !is_same_v<T, string>){
    cout << '{';
    int f = 0;
    for(const auto& i : x) cout << (f++ ? "," : ""),__print(i);
    cout << '}';
  }
  else if constexpr (_p<T>) __print(make_pair(x.first, x.second));
  else cout << x;
}

template <typename T, typename... V>
void _print(T t, V... v){
  __print(t);
  if(sizeof...(v)) cout << ", ";
  _print(v...);
}
#define debug(x...) cout << #x << " = ["; print(x)
