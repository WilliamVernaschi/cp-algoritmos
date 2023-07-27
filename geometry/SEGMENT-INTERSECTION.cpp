#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

ll dotp(P p1, P p2){
    return (conj(p1)*p2).Y;
}

bool boundary(P p1, P p2, P p3){
    P aux1 = p3 - p1;
    P aux2 = p3 - p2;
    if(dotp(aux1, aux2) == 0)
        return min(p1.X, p2.X) <= p3.X && p3.X <= max(p1.X, p2.X)
        && min(p1.Y, p2.Y) <= p3.Y && p3.Y <= max(p1.Y, p2.Y);
    return false;
}

bool sides(P p1, P p2, P p3, P p4){
    P aux1 = p3 - p1;
    P aux2 = p3 - p2;
    if (dotp(aux1, aux2) > 0){
        return dotp(p4 - p1, p4 - p2) < 0;
    }
    if (dotp(aux1, aux2) < 0){
        return dotp(p4 - p1, p4 - p2) > 0;
    }
    return false;
}

bool intersect(P p1, P p2, P p3, P p4){
    return p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4
    || (boundary(p1, p2, p3) || boundary(p1, p2, p4) || boundary(p3, p4, p1) || boundary(p3, p4, p2))
    || (sides(p1, p2, p3, p4) && sides(p3, p4, p1, p2));
}

int main()
{
    int runs; cin >> runs;
    for(int i=0; i<runs; i++){
        int a,b;
        cin >> a >> b;
        P p1 = {a,b};
        cin >> a >> b;
        P p2 = {a,b};
        cin >> a >> b;
        P p3 = {a,b};
        cin >> a >> b;
        P p4 = {a,b};
        if (intersect(p1, p2, p3, p4))
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}