int rob(int* nums, int numsSize)
{
    int a, b, c;
    a = nums[0];
    if (numsSize == 1)
        return a;
    else {
        if (nums[0] > nums[1])
            b = nums[0];
        else
            b = nums[1];
        if (numsSize == 2)
            return b;
        else {
            for (int q = 1;q <= numsSize - 2;q++)
            {
                c = b;
                if (b < a + nums[q + 1])
                    c = a + nums[q + 1];
                a = b;
                b = c;
            }
            return c;
        }
    }
}