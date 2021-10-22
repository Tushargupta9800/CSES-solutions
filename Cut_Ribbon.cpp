#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = INT_MIN;

    for (int i = 0; i <= 4000; i++)
    {
        if (a * i > n)
        {
            break;
        }
        for (int j = 0; j <= 4000; j++)
        {
            if ((a * i + b * j) > n)
            {

                break;
            }
            // if (i == 0 and j == 1)
            // {
            //     cout << (n - (a * i + b * j)) / c << endl;
            // }
            if ((n - (a * i + b * j)) % c == 0)
            {
                int num = (n - (a * i + b * j)) / c;
                ans = max(ans, (i + j + num));
            }
        }
    }
    cout << ans << endl;
}