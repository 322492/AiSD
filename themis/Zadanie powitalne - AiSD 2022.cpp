/*
Kamil Tasarz
322492
KPO
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long it = a;
    while (it % 2022 != 0)
        it++;

    while (it <= b)
    {
        cout << it << " ";
        it += 2022;
    }

    return 0;
}