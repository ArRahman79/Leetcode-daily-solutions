//  24-01-2024

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int travel(struct TreeNode *root,int *arr)
{
    arr[root->val]++;
    if(root->left==NULL && root->right==NULL)
    {
        int count=0;
        for(int i=1;i<=9;i++)
        {
            if(arr[i]%2==1)
            {   count++;    }
        }
        arr[root->val]--;
        if(count>1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int data=0;
    if(root->left!=NULL)
    {
        data+=travel(root->left,arr);
    }
    if(root->right!=NULL)
    {
        data+=travel(root->right,arr);
    }
    arr[root->val]--;
    
    return data;
}

int pseudoPalindromicPaths (struct TreeNode* root) {
    int *arr=(int *)calloc(10,sizeof(int));
    return travel(root,arr);
}
