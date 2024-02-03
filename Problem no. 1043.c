// 03-02-2024

int max(int a,int b)
{
    return a>b?a:b;
}

int t[501];
int solve(int i, int *arr,int k,int arrSize)
{
    if(i>=arrSize)
    {
        return 0;
    }
    if(t[i]!=-1)
    {
        return t[i];
    }
    int res=0,curr_max=-1;
    for(int j=i;j<arrSize && j-i+1<=k;j++)
    {
        curr_max=max(curr_max,arr[j]);
        res=max(res,((j-i+1)*curr_max)+solve(j+1,arr,k,arrSize));
    }
    return t[i]=res;
}

int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    memset(t,-1,sizeof(t));
    return solve(0,arr,k,arrSize);
}
