/*
calculates the area of a convex non-intersecting polygon,
given the coordinates of its points.
area() can return long long if it returns the double of the area
of the polygon.
*/

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define X real()
#define Y imag()
#define ld long double

typedef long long ll;
typedef complex<ll> P;

ll cross_prod(P p1, P p2){
    return (conj(p1)*p2).Y;
}

ld area(vector<P> &vet){
    ll output = 0;
    for(ll i=0; i<vet.size(); i++){
        P p1 = vet[i];
        P p2 = vet[(i+1)%vet.size()];
        output += cross_prod(p1,p2);
    }
    return abs(output) / 2.0L;
}

int main()
{
    int vert; cin >> vert;
    vector<P> vet(vert);
    for (int i=0; i<vert; i++){
        ll a,b; cin >> a >> b;
        vet[i] = {a,b};
    }
    cout << (ll)(2 * area(vet)) << endl;

    return 0;
}