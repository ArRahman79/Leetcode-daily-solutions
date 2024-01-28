//  28-01-2024

int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixColSize[i];j++)
        {
            matrix[i][j]+=i>0 ? matrix[i-1][j] : 0 ;
            matrix[i][j]+=j>0 ? matrix[i][j-1] : 0 ;
            matrix[i][j]-=i>0 && j>0 ? matrix[i-1][j-1] : 0;
        }
    }

    int ans=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixColSize[i];j++)
        {
            for(int ii=0;ii<=i;ii++)
            {
                for(int jj=0;jj<=j;jj++)
                {
                    int sum=matrix[i][j];
                    sum-=ii>0 ? matrix[ii-1][j] : 0 ;
                    sum-=jj>0 ? matrix[i][jj-1] : 0 ;
                    sum+=ii>0 && jj>0 ? matrix[ii-1][jj-1] : 0 ;
                    if(sum==target)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}
