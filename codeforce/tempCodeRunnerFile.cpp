
int qp(int a, int p)
{
    int ans = 1;
    while(p)
    {
        if(p&1)
            ans *= a;
        a *= a;
        p >>= 1;
    }
    return ans;
}
