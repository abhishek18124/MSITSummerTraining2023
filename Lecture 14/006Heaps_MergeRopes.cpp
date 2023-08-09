/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};

    // priority_queue<int, vector<int>, greater<int>> minHeap;

    // for(int rope : ropeLengths) {
    //     minHeap.push(rope);
    // }

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(), ropeLengths.end());

    int totalCost = 0;

    // time : O(nlogn)

    while (minHeap.size() > 1) {

        int firstMin = minHeap.top(); minHeap.pop();
        int secondMin = minHeap.top(); minHeap.pop();

        int costForSingleMerge = firstMin + secondMin;
        totalCost += costForSingleMerge;

        minHeap.push(costForSingleMerge);

    }

    cout << totalCost << endl;


    return 0;
}