class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int store = left;

        for (int i = left; i < right; i++) {
            if (nums[i] > pivot) {
                swap(nums[store], nums[i]);
                store++;
            }
        }
        swap(nums[store], nums[right]);
        return store;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right)
            return nums[left];

        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k) {
            return nums[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(nums, left, pivotIndex - 1, k);
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> maxHeap(nums.begin(), nums.end()); 
    //     for (int i = 1; i < k; i++) {
    //         maxHeap.pop();
    //     }
    //     return maxHeap.top();
    // }
};

