#include <vector>
#include <cmath>

using std::vector;
using std::abs;

/* 时间O(n) 空间O(1)*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 两边遍历
        // 第一遍按abs(下标)标记为负数
        // 第二遍判断不为负数的数字即为消失的数字
        for (int i = 0;i < nums.size();++i) {
            int curr = abs(nums[i]) - 1;
            if (nums[curr] > 0) nums[curr] = -nums[curr];
        }

        vector<int> result;
        for (int i = 0;i < nums.size();++i) {
            if (nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};

/* 时间O(n) 空间O(n)*/
// 遍历待判断的数组，将每个数组去重插入另一个数组，遍历另一个数组找出缺失的数字
