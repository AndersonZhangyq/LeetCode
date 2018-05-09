#include <bits/stdc++.h>

using namespace std;

/**
 * 要找到三个数的和为0，首先对数据进行排序
 * 排序后，按顺序找两个数，随后寻找第三个数，是否能使其和为零。
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    int size = nums.size();
    vector<vector<int>> ans;
    if (size <= 2)
        return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 1; ++i)
    {
        int cur = nums[i];
        int start = i + 1, end = size - 1;
        while (start < end)
        {
            int s = nums[start];
            int e = nums[end];
            printf("start: %d end: %d s: %d e: %d   ", start, end, s, e);
            int sum = cur + s + e;
            if (sum == 0)
            {
                ans.push_back({cur, s, e});
                ++start;
                --end;
                while (start < end && nums[start] == s)
                    ++start;
                while (start < end && nums[end] == e)
                    --end;
            }
            else if (sum > 0)
            {
                --end;
                while (start < end && nums[end] == e)
                    --end;
            }
            else
            {
                ++start;
                while (start < end && nums[start] == s)
                    ++start;
            }
            printf("!!!! start: %d end: %d\n", start, end);
        }
        while (i < size - 1 && nums[i + 1] == cur)
            ++i;
    }
    return ans;
}

int main()
{
    vector<vector<int>> ans;
    vector<int> nums;
    while (true)
    {
        nums.clear();
        int size;
        cin >> size;
        for (int i = 0; i < size; ++i)
        {
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        ans = threeSum(nums);
        for (auto e : ans)
        {
            for (auto i : e)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
