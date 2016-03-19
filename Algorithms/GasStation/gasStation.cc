/*
copyright xu(xusiwei1236@163.com), all right reserved.

Gas Station
============

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].



You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.



Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.



Note:
The solution is guaranteed to be unique.
*/
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, total = 0;

        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (tank < 0) {
                start = i+1;
                tank = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

int main(int argc, char* argv[])
{
    vector<int> gas{4, 3, 2};
    vector<int> cost{5, 2, 1};

    printf("%d\n", Solution().canCompleteCircuit(gas, cost));
    return 0;
}
