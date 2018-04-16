#include <bits/stdc++.h>

using namespace std;

/**
 * 间接寻址排序
 * 首先创建一个数组包含所有的下标，下标从 0 开始
 * 随后根据输入数组的大小关系对应调整下表数组中的元素位置
*/
vector<int> argSort(const vector<int> a)
{
    int length = a.size();
    vector<int> index(length);
    iota(index.begin(), index.end(), 0);
    sort(index.begin(), index.end(), [&a](size_t i, size_t j) {return a[i] < a[j]; });
    return index;
}

/**
 * 由于需要返回数字的下标，直接使用 two point 会产生问题，因为 two point 必须保证所遍历数组是有序的
 * 由此想到使用 间接寻址排序（排序结果是原数组的下表，更具排序结果给出的下标寻找对应元素，依次排列后即为有序数组）
 * 函数 argsort 实现了该功能
 * 随后就是普通的 two point 的思路，两个指针，一个从头开始，一个从末尾开始，向中间靠拢，根据当前两个元素和的大小判断指针如何移动
*/
vector<int> twoSum(vector<int> &nums, int target)
{
    int length = nums.size();
    if (length <= 1)
        return {};
    if (length == 2)
        return {0, 1};
    vector<int> arg = argSort(nums);
    for (int i = 0, j = length - 1; i < j && j >= 0 && i < length;)
    {
        int sum = nums[arg[i]] + nums[arg[j]];
        if (sum == target)
            return {arg[i], arg[j]};
        else if (sum > target)
            --j;
        else
            ++i;
    }
}

int main()
{
    int size;
    while (cin >> size)
    {
        vector<int> nums(size, 0);
        for (int i = 0; i < size; ++i)
        {
            cin >> nums[i];
        }
        int target;
        cin >> target;
        vector<int> ans = twoSum(nums, target);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}