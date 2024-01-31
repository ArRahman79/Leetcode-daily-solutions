// 31-01-2024

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *arr=calloc(temperaturesSize,sizeof(int));
    *returnSize=temperaturesSize;
    int *stack=calloc(temperaturesSize,sizeof(int));
    int count=-1;

    for(int i=temperaturesSize-1;i>=0;i--)
    {
        while(count!=-1 && temperatures[i] >= temperatures[stack[count]])
        {
            count--;
        }
        arr[i]=(count==-1?0:stack[count]-i);
        stack[++count]=i;
    }
    free(stack);
    return arr;
}
