// Longest Consecutive Sequence

//Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//You must write an algorithm that runs in O(n) time.

 

//Example 1:

//Input: nums = [100,4,200,1,3,2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//Example 2:

//Input: nums = [0,3,7,2,5,8,4,6,0,1]
//Output: 9
 
 
 class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); 
        int max_ct = 0;
        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) { 
                int current_num = num;
                int current_ct = 1;
                
                while (numSet.find(current_num + 1) != numSet.end()) {
                    current_num++;
                    current_ct++;
                }
                
                max_ct = max(max_ct, current_ct); 
            }
        }
        
        return max_ct;
    }
};

