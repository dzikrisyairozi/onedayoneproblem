#include <map>
#include <cstdio>
using namespace std; 
typedef long long ll;
map<ll,ll> mp;

ll rec(ll u){
    if(mp.count(u)){
        return mp[u];
    }
    ll nval = rec(u/2) + rec(u/3);
    mp[u] = nval;
    return nval;
}

int main(){
    mp[0] = 1;
    ll u;
    scanf("%lld", &u);
    printf("%lld\n", rec(u));

    return 0;
}