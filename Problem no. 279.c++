08-02-2024

class Solution {
public:
    int arr[10001];
    int help(int n)
    {
        int MinCount=INT_MAX;
        if(n==0)
            return 0;
        else if(arr[n]!=-1)
            return arr[n];
        for(int i=1;i*i<=n;i++)
        {
            int res=1+help(n-(i*i));
            MinCount=min(MinCount,res);
        }
        return arr[n]=MinCount;
    }
    int numSquares(int n) {
        memset(arr,-1,sizeof(arr));
        return help(n);
    }
};
