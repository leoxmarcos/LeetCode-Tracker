class Solution {
public:
void merge(vector<int>& arr, int start, int mid, int end)
{

    vector<int> temp(end - start + 1);

    int left = start;
    int right = mid + 1;
    int index = 0;

    // Compare and merge both sorted halves
    while (left <= mid && right <= end)
    {

        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }

    // Remaining elements of left array
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++;
        left++;
    }

    // Remaining elements of right array
    while (right <= end)
    {
        temp[index] = arr[right];
        index++;
        right++;
    }

    // Copy sorted elements back to original array
    index = 0;

    while (start <= end)
    {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergeSort(vector<int>& arr, int start, int end)
{

    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    // Left half
    mergeSort(arr, start, mid);

    // Right half
    mergeSort(arr, mid + 1, end);

    // Merge both halves
    merge(arr, start, mid, end);
}

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }

};