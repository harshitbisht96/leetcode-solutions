class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    
        if(n <=2 ) {
            return 0;
        }
        int left[n];
        int right[n];
        left[0] = height[0];
        right[n-1] = height[n-1];
        //populate height with the maximum height on left for every index
        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        //populate height with maximum height on right for every index
        for(int i=n-2; i>=0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans+=min(left[i], right[i])-height[i];
        }
        return ans;
    }
};