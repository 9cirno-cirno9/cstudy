class Solution {
public:
    int maxDistance(vector<int>& colors)
    {
        int left = 0;
        int max = 0;
        int right = colors.size() - 1;
        while (left <= colors.size() - 1 && right >= 0)
        {
            if (colors[left] != colors[colors.size() - 1])
            {
                max = colors.size() - 1 - left;
                break;
            }
            else
                left++;
            if (colors[right] != colors[0])
            {
                max = right - 0;
                break;
            }
            else
                right--;
        }
        return max;
    }
};