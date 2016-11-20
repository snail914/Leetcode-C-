/*
Given a sorted positive integer array nums and an integer n, 
add/patch elements to the array such that any number in range [1, n] 
inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

*/


/*
Assume the upper bound we can not reach is miss, i.e the largest number we can reach is (miss-1), i.e we can already reach number among [1, miss-1] (both inclusive), what number should we patch to reach miss?
We can patch any number among [1, miss] (both inclusive), but only patching the largest number can make sure we patch least count of numbers, because the by patching the largest number, we extend to the largest upper bound.
For example currently the upper bound is miss, so we can already reach [1, miss-1], the after patching miss, the largest number we can reach is miss-1+miss, so then upper bound becomes miss + miss;
*/


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());

        long miss = 1;
        int count = 0;
        int i = 0;
        while (miss <= n){
            if (i < nums.size() && nums[i] <= miss){
                miss += nums[i];
                i++;
            }else{
                count++; // insert number miss
                miss += miss;           
            }
        }
        return count;
    }
};