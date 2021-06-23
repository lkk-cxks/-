#include<bits/stdc++.h>
#define min(x,y) ((x) > (y)?(y):(x))
//using namespace std;
int edit(char *S,char *T)
{
    int sLen = strlen(S);
    int tLen = strlen(T);
    int dp[sLen+1][tLen+1];
    int i = 0;
    int j = 0;
    for ( i = 1;i <= sLen;i++)
        dp[i][0] = i;
    for ( j = 1;j <= tLen;j++)
        dp[0][j] = j;
    for ( i = 1;i <= sLen;i++)
    {
        for (j = 1;j <= tLen;j++)
        {
            if (S[i-1] == T[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);//注意这里两个min
            }
        }
    }
    return dp[sLen][tLen];
}
int main()
{
	char S[1000],T[1000];
	printf("输入原串：\n");
    gets(S);
    printf("输入目标串：\n");
    gets(T);
    printf("最小操作数：\n");
    printf("%d\n",edit(S,T));
    return 0;
}

