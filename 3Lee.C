#include<string.h>
#include<stdio.h>

int GetState(char *s,int star,int end )//用来扫描字符串有没有重复
{
    int i;
    for(i = star; i < end; i++)
    {
        if(s[i]==s[end])
        {
            return 1;//重复则返回1
        }
    }
    return 2;
}

int lengthOfLongestSubstring(char * s)
{
    int i = 0;
    int j = i+1;
    int max = 1;
    int len;
    int ret = 0;
    int count = 0;

    len = strlen(s);
    if(len == 0)
    {
        return 0;
    }
    while(j < len)
    {
        ret = GetState(s, i , j);//先扫描1和2的位置是否重复
        if(ret == 1)//重复了i+1，相当于头+1
        {
            i++;
        }
        else//否则count表示不同的字串数
        {
            count = j-i+1;
            j++;//向后扫描
        }

        if(count > max)//赋值大的
        {
            max = count;
        }
    }
    return max;
}
