
class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int x;
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1;i <= nums.size();i++)
        {
            x = nums[i - 1];
            if (x != 0)
            {
                for (int k = i;k <= nums.size();k++)
                {
                    nums[k - 1] -= x;
                }
                count++;
            }

        }
        return count;
    }
};