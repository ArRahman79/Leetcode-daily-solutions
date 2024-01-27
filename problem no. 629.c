//  27-01-2024

/*
      k:    0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
n=    0:    1
n=    1:    1
n=    2:    1    1
n=    3:    1    2    2    1
n=    4:    1    3    5    6    5    3    1
n=    5:    1    4    9   15   20   22   20   15    9    4    1
n=    6:    1    5   14   29   49   71   90  101  101   90   71   49   29   14    5    1
*/
// sum = above arr of n as like n=5 ,k=6
// so we add element in arr[5][6]=see above array index 6 to 2 this all the index is n=5 terms

int kInversePairs(int n, int k)
{
    int arr[n+1][k+1],mod=1000000007;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j>0)
            {
                arr[i][j]=0;
            }
            else
            {
                arr[i][0]=1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        long long sum=1;
        for(int j=1;j<=k;j++)
        {
            sum+=arr[i-1][j];
            if(j>=i)
            {
                sum-=arr[i-1][j-i];
            }
            arr[i][j]=sum%mod;
        }
    }
    return arr[n][k];
}
