//最接近的三数之和
int threeSumClosest(int* nums, int numsSize, int target) {
    int min_sum = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = sum - target > 0 ? sum - target : target - sum; // abs
                int min_diff = min_sum - target > 0 ? min_sum - target : target - min_sum; // abs
                if (diff < min_diff) {
                    min_sum = sum;
                }
            }
        }
    }
    return min_sum;
}
//四数之和
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int ki = 0; ki < length - 3; ki++) {
            if (ki != 0 && nums[ki] == nums[ki - 1]) continue;
            long long  curtarget = target - nums[ki];
            for (int i = ki + 1; i < length - 2; i++) {
                if (i != ki + 1 && nums[i - 1] == nums[i]) continue;
                for (int j = i + 1; j < length - 1; j++) {
                    if (j != i + 1 && nums[j - 1] == nums[j])  continue;
                    long long  three = curtarget - (nums[i] + nums[j]);
                    if (check(j + 1, length - 1, three, nums)) {
                        vector<int> retItem;
                        retItem.push_back(nums[ki]);
                        retItem.push_back(nums[i]);
                        retItem.push_back(nums[j]);
                        retItem.push_back(three);

                        res.push_back(retItem);
                    }
                }
            }

        }

        return res;
    }
    bool check(int L, int R, long long  num, vector<int>& nums) {
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (nums[mid] == num) return true;
            else if (nums[mid] > num) R = mid - 1;
            else L = mid + 1;
        }
        return false;
    }
};
//反转数字
#include <stdio.h>
#include <string.h>

void reverseString(char* str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main() {
    char input[6]; 
    char processed[5]; 
    printf("输入一个三位整数加一位小数的浮点数（如123.4）: ");
    scanf("%5s", input); 
    int j = 0;
    for (int i = 0; i < 5; i++) {
        if (input[i] != '.') {
            processed[j++] = input[i];
        }
    }
    processed[4] = '\0'; 
    reverseString(processed, 4);
    printf("输出结果: %c.%c%c%c\n",
        processed[0], processed[1], processed[2], processed[3]);

    return 0;
}