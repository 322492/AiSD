#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define LL long long
#define PLL pair<long long, long long>
#define tpl tuple<long long, pair<long long, long long>, pair<long long, long long>>

int n, x, y;
tpl res; //(odleglosc, punkt A, punkt B)
PLL A, B;
vector<PLL> wej; // wejscie, a potem posortowane po x
vector<PLL> Y;   // wejscie posortowane po y

long long dist(LL x1, LL y1, LL x2, LL y2) // kwadrat odleglosci
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

tpl srodek(vector<PLL> yyy, LL d, int a, int b) //znajduje najblizsze pukty lezace blisko (nie dalej niz o d) srodkowej linii
{
    vector<PLL> bliskie;
    bliskie.clear();

    tpl wyn = make_tuple(dist(wej[a].f, wej[a].s, wej[b].f, wej[b].s), wej[a], wej[b]);

    int i = (a + b) / 2;
    LL m = wej[i].f;
    for (int i = 0; i < yyy.size(); i++)
    {
        if (abs(yyy[i].f - m) < d)
            bliskie.push_back(yyy[i]);
    }

    for (int i = 0; i < bliskie.size(); i++)
    {
        int j = i + 1;
        while (j < bliskie.size() && bliskie[j].s - bliskie[i].s <= d) //mozna udowodnic ze obrotow tej petli jest nie wiecej niz 7, dlatego jest to szybkie
        {
            LL nd = dist(bliskie[i].f, bliskie[i].s, bliskie[j].f, bliskie[j].s);
            if (nd < get<0>(wyn))
                wyn = make_tuple(nd, bliskie[i], bliskie[j]);
            j++;
        }
    }
    return wyn;
}

tpl rec(vector<PLL> yyy, int a, int b) //glowna rekurencja
{
    if (b - a == 1) // dwa punkty
    {
        return make_tuple(dist(wej[a].f, wej[a].s, wej[b].f, wej[b].s), wej[a], wej[b]);
    }
    if (b - a == 2) // trzy punkty
    {
        PLL A = wej[a], B = wej[a + 1], C = wej[b];
        tpl w = make_tuple(dist(A.f, A.s, B.f, B.s), A, B);
        if (get<0>(w) > dist(A.f, A.s, C.f, C.s))
            w = make_tuple(dist(A.f, A.s, C.f, C.s), A, C);
        if (get<0>(w) > dist(B.f, B.s, C.f, C.s))
            w = make_tuple(dist(B.f, B.s, C.f, C.s), B, C);
        return w;
    }

    vector<PLL> YL, YR;
    YL.clear();
    YR.clear();
    LL xm = wej[(a + b) / 2].f;
    for (int i = 0; i < yyy.size(); i++)
    {
        if (yyy[i].f < xm || (yyy[i].f == xm && yyy[i].s <= wej[(a + b) / 2].f))
            YL.push_back(yyy[i]);
        else
            YR.push_back(yyy[i]);
    }

    tpl dl = rec(YL, a, (a + b) / 2); //minimum z lewej strony
    tpl dr = rec(YR, (a + b) / 2 + 1, b); //minimum z prawej strony

    tpl wyn = dr;
    if (get<0>(dl) < get<0>(dr))
        wyn = dl;

    tpl ds = srodek(yyy, get<0>(wyn), a, b); //minimum z punktow lezacych blisko srodkowej linii
    if (get<0>(wyn) < get<0>(ds))
        return wyn;
    else
        return ds;
}

bool comp(PLL a, PLL b) //sortuje wzgledem drugiej wspolrzednej
{
    if (a.s != b.s)
        return a.s < b.s;
    return a.f < b.f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        wej.push_back({x, y});
    }

    Y = wej;
    sort(wej.begin(), wej.end());
    sort(Y.begin(), Y.end(), comp);

    tpl d = rec(Y, 0, n - 1);
    A = get<1>(d);
    B = get<2>(d);
    cout << A.f << " " << A.s << "\n"
         << B.f << " " << B.s;

    return 0;
}