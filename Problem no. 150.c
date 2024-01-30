// 30-01-2024

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top=-1,count;
    for(int i=0;i<tokensSize;i++)
    {
        if(strcmp(tokens[i],"+")==0)
        {
            count=stack[top--];
            stack[top]=stack[top]+count;
        }
        else if(strcmp(tokens[i],"-")==0)
        {
            count=stack[top--];
            stack[top]=stack[top]-count;
        }
        else if(strcmp(tokens[i],"*")==0)
        {
            count=stack[top--];
            stack[top]=stack[top]*count;
        }
        else if(strcmp(tokens[i],"/")==0)
        {
            count=stack[top--];
            stack[top]=stack[top]/count;
        }
        else
        {
            stack[++top]=atoi(tokens[i]);  //atoi()=convert string to integer
        }
    }
    return stack[top];
}
