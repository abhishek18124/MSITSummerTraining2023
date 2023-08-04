#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int validSubarrays(vector<int>& nums) {

   int n = nums.size();

   vector<int> out;
   stack<pair<int, int>> s; // <value, index>

   for (int i = n - 1; i >= 0; i--) {

      // find the index of the nearest smaller element to the right of nums[i]

      while (!s.empty() and s.top().first >= nums[i]) {
         s.pop();
      }

      if (s.empty()) {

         // nums[i] doesn't have a smaller element to its right

         out.push_back(n);


      } else {

         out.push_back(s.top().second);

      }

      s.push({nums[i], i});

   }

   reverse(out.begin(), out.end());

   for (int i = 0; i < out.size(); i++) {
      cout << out[i] << " ";
   }

   cout << endl;

   int count = 0; // to track the no. of valid subarrays

   for (int i = 0; i < out.size(); i++) {

      // find the no. of valid subarrays that start at the ith index

      count += out[i] - i;

   }

   return count;

}

int main() {

   vector<int> nums = {1, 4, 2, 5, 3, 9};

   cout << validSubarrays(nums) << endl;

}