//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
int reverse(int x){
    long sum = 0;//防止超过最大范围
    while(x)
    {
        sum = sum*10 + x%10;
        x = x/10;
    }
    if(sum > INT_MAX || sum < INT_MIN) //判断界限
    return 0;
    return sum;
}