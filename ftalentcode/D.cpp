#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define fu(i, a, b) for (int i = a; i <= b; ++i)
#define fd(i, a, b) for (int i = a; i >= b; --i)

int main()
{
    int n;
    cin >> n;
    vector<vector<double>> a(n + 1, vector<double>(n + 1));
    vector<double> b(n + 1);

    fu(i, 1, n)
    {
        fu(j, 1, n)
        {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    // Gaussian elimination
    fu(i, 1, n)
    {
        int p = i;
        fu(j, i + 1, n)
        {
            if (abs(a[j][i]) > abs(a[p][i]))
                p = j;
        }
        swap(a[i], a[p]);
        swap(b[i], b[p]);

        fu(j, i + 1, n)
        {
            if (a[i][i] == 0)
            {
                if (b[i] != 0)
                {
                    cout << "No solution" << endl;
                    return 0;
                }
                continue;
            }
            double x = a[j][i] / a[i][i];
            fu(k, i, n)
            {
                a[j][k] -= a[i][k] * x;
            }
            b[j] -= b[i] * x;
        }
    }

    // Check for no solution in the final matrix
    // fu(i, 1, n)
    // {
    //     bool allZero = true;
    //     fu(j, 1, n)
    //     {
    //         if (a[i][j] != 0)
    //         {
    //             allZero = false;
    //             break;
    //         }
    //     }
    //     if (allZero && b[i] != 0)
    //     {
    //         cout << "No solution" << endl;
    //         return 0;
    //     }
    // }

    // Back substitution
    vector<double> res(n + 1);
    fd(i, n, 1)
    {
        fu(j, i + 1, n)
        {
            b[i] -= a[i][j] * res[j];
        }
        res[i] = b[i] / a[i][i];
        if (a[i][i] == 0)
        {
            cout << "ERROR" << endl;
            return 0;
        }
    }

    // Print the solution
    fu(i, 1, n)
    {
        cout << fixed << setprecision(6) << res[i] << "\n";
    }

    return 0;
}