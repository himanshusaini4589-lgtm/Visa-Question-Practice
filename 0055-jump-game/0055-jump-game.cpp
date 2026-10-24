class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> zero;
        for(int i = 0 ; i<n ; i++){
            if(nums[i]==0) zero.push_back(i);
        }
        if(nums[0]==0 && nums.size()>1) return false;
        if(zero.size()==0) return true;

        int maxi = nums[0];
        for(int i = 1 ; i<n ; i++){
            if(nums[i] + i > maxi){
                maxi = nums[i] + i;
            }
            if(maxi >= n-1) return true;
            if(maxi == i) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna