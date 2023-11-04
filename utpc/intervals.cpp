#include "testlib.h"
#include <iostream>
#include <set>

using namespace std;

// used for larger stress tests, generates intervals in sizes 1, ... n and queries the entire range for them
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    const int max_v = (int)1e9;
    const int max_c = (int)1e9;

    set<int> used;

    cout << n << "\n";

    int cnt = 0;
    for (int s = 1; s < n; s++)
    {
        while (1)
        {
            int start = rnd.next(1, max_v - s);
            bool good = 1;
            // verify that the interval is clear
            for (int i = 0; i < s; i++)
            {
                if (used.count(start + i))
                {
                    good = 0;
                    break;
                }
            }

            if (!good)
                continue;

            for (int i = 0; i < s; i++)
            {
                cout << "0 " << start + i << " " << rnd.next(1, max_v) << "\n";
                cnt++;
                if (cnt >= n)
                    return 0;
                used.insert(start + i);
            }

            cout << "1 0 " << max_c << "\n";
            cnt++;
            if (cnt >= n)
                return 0;
            break;
        }
    }
}