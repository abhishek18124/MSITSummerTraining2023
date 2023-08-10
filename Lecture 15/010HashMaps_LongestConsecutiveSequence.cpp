#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {

    unordered_map<int, bool> startMap;

    // time : O(n)

    for (int i = 0; i < nums.size(); i++) {

        // check if nums[i] can be starting point for a sequence of consecutive elements

        if (startMap.find(nums[i] - 1) == startMap.end()) {
            startMap[nums[i]] = true;
        } else {
            startMap[nums[i]] = false;
        }

        if (startMap.find(nums[i] + 1) != startMap.end()) {
            // nums[i] + 1 cannot be the start
            startMap[nums[i] + 1] = false;
        }

    }

    // time : O(n)

    int maxLen = 0;

    for (pair<int, bool> p : startMap) {
        int element = p.first;
        bool canStart = p.second;

        if (canStart) {

            int count = 0;
            int key = element;
            while (startMap.find(key) != startMap.end()) {
                count++;
                key++;
            }

            maxLen = max(maxLen, count);

        }

    }

    return maxLen;

}

int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2, 101, 201, 102};

    cout << longestConsecutive(nums) << endl;

    return 0;
}

