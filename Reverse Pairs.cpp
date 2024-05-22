// Reverse Pairs

//Given an integer array nums, return the number of reverse pairs in the array.

//A reverse pair is a pair (i, j) where:

//0 <= i < j < nums.length and
//nums[i] > 2 * nums[j].
 

//Example 1:

//Input: nums = [1,3,2,3,1]
//Output: 2
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1


//Example 2:

//Input: nums = [2,4,3,5,1]
//Output: 3
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
//(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1




class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }

    int merge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp(right - left + 1);
        int i = left, k = mid + 1, t = 0;

        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp[t++] = nums[i++];
            } else {
                temp[t++] = nums[k++];
            }
        }

        while (i <= mid) {
            temp[t++] = nums[i++];
        }

        while (k <= right) {
            temp[t++] = nums[k++];
        }

        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }

        return count;
    }
};

