#include <bits/stdc++.h>

using namespace std;

/**
 * 目标是最大化 (min(a[i], a[j]) * (j - i + 1) (0 <= i,j < n, i != j)
 * 可以使用贪心策略，每次将短边向长边靠近
*/
int maxArea(vector<int> &height)
{
    int size = height.size();
    if (size < 2)
    {
        return 0;
    }
    if (size == 2)
    {
        return min(height[0], height[1]);
    }
    int ans = 0;
    int i = 0, j = size - 1;
    while (i < j)
    {
        int h = min(height[i], height[j]);
        ans = max(ans, h * (j - i));
        if (h == height[i])
        {
            while (h == height[i])
                ++i;
        }
        else
        {
            while (h == height[j])
                --j;
        }
    }
    return ans;
}

int main()
{

    return 0;
}
