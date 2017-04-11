#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n = 5;
    if (argc > 1) n = atoi(argv[1]);

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    do {
        cout << "{";
        for (int i = 0; i < n; i++) {
            cout << v[i] << (i + 1 != n ? "," : "");
        }
        cout << "}\n";
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
