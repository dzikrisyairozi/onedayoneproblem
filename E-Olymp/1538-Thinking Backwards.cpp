#include <stdio.h>
#include <math.h>
typedef long long ll;
using namespace std;

ll solution(ll b, ll c) {
    ll d = b * b - 4 * c;
    if(d >= 0)
    {
        ll o = (ll)(sqrt(d) + 0.5);
        ll s = -b + o;
        if(s % 2 == 0 && d == o * o)
            return s/2;
    }
    return -1;
}

int main() {
    ll x;
    int y=1;
    scanf("%lld",&x);
    while(x != -1)
    {
        printf("Case %d:\n",y++);
        if(x == 1)
            printf("0 0 0\n");
        else if(x == 0 || x % 2 == 1)
            printf("Impossible.\n");
        else {
            bool impos = true;
            for(int ellipse = 1; ellipse <= 100; ellipse++)
            {
                ll tmp = 2 * (ellipse-1) * (ellipse-2) + 2;
                if(tmp > x)
                    break;
                for(int triangle = 100; triangle > 0; triangle--)
                {
                    ll b = 6 * (triangle-1) + 4 * (ellipse-1) - 1;
                    ll c = 3 * (triangle-1) * (triangle-2) + 6 * (ellipse-1) * (triangle-1) + tmp;
                    if(c > x)
                        continue;
                    c -= x;
                    ll circle = solution(b,c);
                    if(circle >= 0 && circle < 20000)
                    {
                        printf("%d %lld %d\n", ellipse-1, circle, triangle-1);
                        impos = false;
                    }
                }
            }
            if(impos)
                printf("Impossible.\n");
        }
        scanf("%lld",&x);
    }
    return 0;
}