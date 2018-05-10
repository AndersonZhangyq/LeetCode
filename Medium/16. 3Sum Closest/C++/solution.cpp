#include <bits/stdc++.h>

using namespace std;

/**
 * 先将数组排序，排序后从第 i 个数开始，在 i+1 到 末位这一段里用 two point 的方法找出最优解
*/
int threeSumClosest(vector<int> &nums, int target)
{
    int size = nums.size();
    if (size <= 2)
        return -1;
    sort(nums.begin(), nums.end());
    int ans, min_gap = INT_MAX;
    int i = 0;
    while(i < size - 2){
        int start = i + 1;
        int end = size - 1;
        int cur = nums[i];
        while(start < end){
            int s = nums[start], e = nums[end];
            int sum = cur + s + e;
            if (sum == target)
                return target;
            else if (sum > target){
                if (abs(sum - target) < min_gap){
                    min_gap = abs(sum - target);
                    ans = sum;
                }
                --end;
                while (start < end && nums[end] == e)
                    --end;
            }else{
                if (abs(sum - target) < min_gap){
                    min_gap = abs(sum - target);
                    ans = sum;
                }
                ++start;
                while (start < end && nums[start] == s)
                    ++start;
            }
        }
        ++i;
    }
    return ans;
}

int main()
{
    while(true){
        int size;
        cin >> size;
        vector<int> nums;
        for(int i = 0; i < size; ++i){
            int tmp;
            cin >> tmp;
            nums.push_back(tmp);
        }
        int target;
        cin >> target;
        cout << threeSumClosest(nums, target) << endl;
    }
    return 0;
}
