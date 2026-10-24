class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int> >ne;
        for(int i = 0 ; i<n ; i++){
            ne.push_back({nums[i],i});
        }
        sort(ne.begin(),ne.end());
        int l = 0;
        int r = n-1;
        while(l<r){
            int sum = ne[l].first + ne[r].first;
            if(sum==target){
                return {ne[l].second,ne[r].second};
            }

            if(sum > target) r--;
            else l++;
        }

        return {-1,-1};

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna