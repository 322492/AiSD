#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    if (b < a)
        swap(a, b);

    for (int i = a; i <= b; i++)
        cout << i << "\n";

    return 0;
}