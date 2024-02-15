//  15/02/2024

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long long int j,n=nums.size();
        for(long long int i=0;i<n;i++)
        {
            long long int add=0;
            long long int minus=nums[n-i-1];
            for(j=0;j<n-i-1;j++)
            {
                add=add+nums[j];
            }
            if(add>minus)
                return add+minus;
            if(j==1)
                return -1;
        }
        return -1;
    }
};
