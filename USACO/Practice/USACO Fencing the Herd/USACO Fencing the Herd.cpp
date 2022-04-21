#include "USACO Fencing the Herd.h"
using namespace std;
#define EPS 1e-9
typedef double num;
inline num nabs(num x)
{
    return x < 0 ? -x : x;
}
bool num_lt(num X, num Y)
{
    return X + max(num(1), nabs(Y)) * EPS < Y;
}
bool num_lteq(num X, num Y)
{
    return X <= Y + max(num(1), nabs(Y)) * EPS;
}
bool num_eq(num X, num Y)
{
    return num_lteq(X, Y) && num_lteq(Y, X);
}
typedef complex<num> Point;
typedef vector<Point> poly;
num cp(Point A, Point B, Point C = Point(0, 0))
{
    return imag(conj(A - C) * (B - C));
}
bool ccw(Point A, Point B, Point C)
{
    return num_lt(0, cp(A, B, C));
}
bool ccweq(Point A, Point B, Point C)
{
    return num_lteq(0, cp(A, B, C));
}
num dot(Point A, Point B, Point C = Point(0, 0))
{
    return real(conj(A - C) * (B - C));
}
Point pivot;
bool pointCmp(Point A, Point B)
{
    return make_pair(A.real(), A.imag()) < make_pair(B.real(), B.imag());
}
bool angleCmp(Point A, Point B)
{
    num c = cp(pivot, A, B);
    return num_eq(c, 0) && dot(A, A, pivot) < dot(B, B, pivot) || num_lt(0, c);
}
void unwind(poly& P, Point A)
{
    int sz = P.size();
    while (sz > 1 && ccweq(A, P[sz - 1], P[sz - 2])) --sz;
    P.resize(sz);
}
poly hull(poly P)
{
    swap(P[0], *min_element(P.begin(), P.end(), pointCmp));
    pivot = P[0];
    sort(P.begin() + 1, P.end(), angleCmp);
    poly ret(1, pivot);
    for (int i = 1; i < int(P.size()); i++)
    {
        unwind(ret, P[i]);
        ret.push_back(P[i]);
    }
    if (ret.size() > 2)
    {
        unwind(ret, pivot);
    }
    return ret;
}
bool radial_compare(Point x, Point y, Point base = Point(1, 0))
{
    num cx = cp(base, x);
    num cy = cp(base, y);
    if (num_eq(cx, 0))
    {
        cx = dot(base, x);
    }
    if (num_eq(cy, 0))
    {
        cy = dot(base, y);
    }
    if ((cx < 0) == (cy < 0))
    {
        return ccw(0, x, y);
    }
    return cy < 0;
}
num convex_max_dot(const poly& P, Point pt)
{
    int lo = 0;
    int hi = P.size() - 1;
    Point base = P[0] - P.back();
    while (lo < hi)
    {
        int md = (lo + hi + 1) / 2;
        Point v = P[md] - P[md ? md - 1 : P.size() - 1];
        if (radial_compare(v, pt * Point(0, 1), base))
        {
            lo = md;
        }
        else
        {
            hi = md - 1;
        }
    }
    return dot(P[lo], pt);
}
struct dyn_hull
{
    dyn_hull()
    {
    }
    void add(Point pt)
    {
        poly p(1, pt);
        for (int i = 0; i < int(hulls.size()); i++)
        {
            if (hulls[i].empty())
            {
                hulls[i] = hull(p);
                return;
            }
            for (int j = 0; j < int(hulls[i].size()); j++)
            {
                p.push_back(hulls[i][j]);
            }
            hulls[i].clear();
        }
        hulls.push_back(hull(p));
    }
    num max_dot(Point pt)
    {
        num ret = 0;
        bool init = false;
        for (int i = 0; i < int(hulls.size()); i++)
        {
            if (hulls[i].empty())
            {
                continue;
            }
            num res = convex_max_dot(hulls[i], pt);
            if (!init || res > ret)
            {
                init = true;
                ret = res;
            }
        }
        return ret;
    }
    bool empty()
    {
        return hulls.empty();
    }
    vector<poly> hulls;
};
void usacofencingrun()
{
    ios_base::sync_with_stdio(false);
    freopen("fencing.in", "r", stdin);
    freopen("fencing.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    poly h0;
    for (int i = 0; i < N; i++)
    {
        num x, y;
        cin >> x >> y;
        h0.push_back(Point(x, y));
    }
    h0 = hull(h0);
    dyn_hull h;
    for (int i = 0; i < Q; i++)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 1)
        {
            num x, y;
            cin >> x >> y;
            h.add(Point(x, y));
        }
        else
        {
            num a, b, c;
            cin >> a >> b >> c;
            Point pt(a, b);
            if ((dot(h0[0], pt) <= c || -convex_max_dot(h0, -pt) <= c || (!h.empty() && -h.max_dot(-pt) <= c)) && (dot(h0[0], pt) >= c || convex_max_dot(h0, pt) >= c || (!h.empty() && h.max_dot(pt) >= c)))
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
}