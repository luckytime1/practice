//两数相加
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = NULL;
    struct ListNode* h = result;
    if (l1->val == 0 && l2->val == 0 && l1->next == NULL && l2->next == NULL)return result;
    else {
        int high = 0;
        int sum = 0;
        int n1 = 0;
        int n2 = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                n1 = l1->val;
                l1 = l1->next;
            }
            else {
                n1 = 0;
            }
            if (l2 != NULL) {
                n2 = l2->val;
                l2 = l2->next;
            }
            else {
                n2 = 0;
            }
            sum = n1 + n2 + high;
            if (sum >= 10)high = 1;
            else high = 0;
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = sum % 10;
            newNode->next = NULL;
            h->next = newNode;
            h = newNode;
        }
        if (high == 1) {
            struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode->val = 1;
            newNode->next = NULL;
            h->next = newNode;
            h = newNode;
        }
        return result->next;
    }
    return 0;
}
//删去有序数组中的重复项
int removeDuplicates(int* nums, int numsSize) {
    int count = 1;
    int result = 1;
    int i = 0;
    for (i = 1;i < numsSize;i++) {
        if (nums[i] == nums[i - 1])
            count++;
        else
            count = 1;

        if (count == 1)
        {
            nums[result] = nums[i];
            result++;
        }
    }
    return result;
}
int removeDuplicates(int* nums, int numsSize) {
    int count=1;
    int result=1;
    int i=0;
    for(i=1;i<numsSize;i++){
        if(nums[i]==nums[i-1])
            count++;
        else
            count=1;
        
        if(count==1)
        {
            nums[result]=nums[i];
            result++;
        }
    }
    return result;
}
//三数之和
int cmp(const void* a, const void* b) {
    const int* aa = a;
    const int* bb = b;
    return (*aa > *bb) - (*aa < *bb);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int n = numsSize;
    qsort(nums, n, sizeof(int), cmp);
    int** ans;
    int rstSize = 0, basicSize = 8;
    ans = (int**)malloc(sizeof(int*) * basicSize);
    *returnColumnSizes = (int*)malloc(sizeof(int*) * basicSize);

    for (int target = 0; target < n - 1; target++) {
        if (target > 0 && nums[target] == nums[target - 1]) continue;
        int left = target + 1, right = n - 1;
        while (left < right) {
            int sum = nums[target] + nums[left] + nums[right];
            if (sum == 0) {
                ans[rstSize] = (int*)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[rstSize] = 3;
                ans[rstSize][0] = nums[target];
                ans[rstSize][1] = nums[left];
                ans[rstSize][2] = nums[right];
                rstSize++;
                while (left < right && nums[left] == nums[left + 1]) left++;
                left++, right--;
                if (rstSize == basicSize) {
                    basicSize *= 2;
                    ans = (int**)realloc(ans, sizeof(int*) * basicSize);
                    (*returnColumnSizes) = (int**)realloc((*returnColumnSizes), sizeof(int*) * basicSize);
                }
            }
            else if (sum > 0) {
                right--;
            }
            else {
                left++;
            }
        }
    }
    *returnSize = rstSize;
    return ans;
}