//  26-01-2024

int arr[51][51][51];
int mod=1000000007;
long find(int m,int n, int maxMove,int i,int j)
{
    if(i>=m || i<0 || j>=n || j<0)
    {
        return 1;
    }
    if(maxMove<=0)
    {
        return 0;
    }
    if(arr[i][j][maxMove]!=-1)
    {
        return arr[i][j][maxMove];
    }
    long result=0;
    result+=find(m,n,maxMove-1,i-1,j);
    result+=find(m,n,maxMove-1,i+1,j);
    result+=find(m,n,maxMove-1,i,j+1);
    result+=find(m,n,maxMove-1,i,j-1);
    return arr[i][j][maxMove]=result%mod;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    memset(arr,-1,sizeof(arr));
    return find(m,n,maxMove,startRow,startColumn)%mod;
}
