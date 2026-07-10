/*APPROACH: 
-->Compare nums[mid] with nums[high].
-->If nums[mid] > nums[high], the minimum is in the right half, so move low = mid + 1.
-->Otherwise, the minimum is at mid or in the left half, so move high = mid, until low == high.
-->The element at nums[low] is the minimum*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return nums[low];
    }
};