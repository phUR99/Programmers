#include <vector>
#include <numeric>
using namespace std;

int solution(vector<vector<int>> signals)
{
    int lcm = 1;

    for (auto &s : signals)
    {
        int period = s[0] + s[1] + s[2];
        lcm = lcm / gcd(lcm, period) * period;
    }

    for (int t = 0; t < lcm; t++)
    {
        bool allYellow = true;

        for (auto &s : signals)
        {
            int G = s[0];
            int Y = s[1];
            int R = s[2];

            int period = G + Y + R;

            int pos = t % period;

            // [G, G+Y) 구간이 노란불
            if (pos < G || pos >= G + Y)
            {
                allYellow = false;
                break;
            }
        }

        if (allYellow)
            return ++t;
    }

    return -1;
}