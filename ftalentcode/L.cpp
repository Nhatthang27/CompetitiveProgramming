#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const double EPSILON = 1e-9;

struct Part
{
    int index;
    double deviation;
    bool operator<(const Part &other) const
    {
        return deviation > other.deviation;
    }
};

int main()
{
    int n;
    double k;
    cin >> n >> k;
    vector<double> a(n), s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    priority_queue<Part> pq;
    double totalDeviation = 0.0;
    for (int i = 0; i < n; ++i)
    {
        double deviation = fabs(a[i] - s[i]) / s[i];
        totalDeviation += deviation;
        pq.push({i, deviation});
    }

    int time = 0;
    while (totalDeviation > k + EPSILON)
    {
        Part part = pq.top();
        pq.pop();
        int i = part.index;
        double currentDeviation = part.deviation;

        if (a[i] > s[i])
        {
            a[i]--;
        }
        else
        {
            a[i]++;
        }

        double newDeviation = fabs(a[i] - s[i]) / s[i];
        totalDeviation = totalDeviation - currentDeviation + newDeviation;
        pq.push({i, newDeviation});
        time++;
    }

    cout << time << endl;
    return 0;
}