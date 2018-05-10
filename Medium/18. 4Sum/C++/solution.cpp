#include <bits/stdc++.h>

using namespace std;

/**
 * 对数据进行排序，排完序后，选定两个，对剩余用 two point
*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int size = nums.size();
    vector<vector<int>> ans;
    if (size < 4)
        return ans;
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < size - 3)
    {
        int cur_i = nums[i];
        int j = i + 1;
        while (j < size - 2)
        {
            int cur_j = nums[j];
            if (cur_i + cur_j > target && nums[j + 1] >= 0)
                break;
            int start = j + 1, end = size - 1;
            while (start < end)
            {
                int s = nums[start], e = nums[end];
                int sum = cur_i + cur_j + s + e;
                if (sum == target)
                {
                    ans.push_back({cur_i, cur_j, s, e});
                    ++start;
                    --end;
                    while (start < end && nums[start] == s)
                        ++start;
                    while (start < end && nums[end] == e)
                        --end;
                }
                else if (sum > target)
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
            }
            ++j;
            while (j < size - 2 && nums[j] == cur_j)
                ++j;
        }
        ++i;
        while (i < size - 3 && nums[i] == cur_i)
            ++i;
    }
    return ans;
}

int main()
{
    while (true)
    {
        int size;
        cin >> size;
        vector<int> nums(size, 0);
        for (int i = 0; i < size; ++i)
        {
            cin >> nums[i];
        }
        int target;
        cin >> target;
        vector<vector<int>> ans = fourSum(nums, target);
        for (auto a : ans)
        {
            for (auto i : a)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
