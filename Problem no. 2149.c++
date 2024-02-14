//  14-02-2024

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size(),a=0,b=0;
        vector<int>arr(n/2);
        vector<int>brr(n/2);
        vector<int> newarr(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                arr[a++]=nums[i];
            }
            else
            {
                brr[b++]=nums[i];
            }
        }

        a=0;    b=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                newarr[i]=arr[a++];
            }
            else
            {
                newarr[i]=brr[b++];
            }
        }
        return newarr;
    }
};
