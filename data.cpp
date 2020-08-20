#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << 1<<endl;
    srand((int)time(0)); 
    int p, s;
    p = s = 1;
    while(s==p)
    {
        s = rand()%4+1;
        p = rand()%5+s;
    }
    cout <<s<<' '<<p<<endl;
    for (int i = 0; i < p; i++)
        cout<<rand()%400<<' '<<rand()%400<<endl;
    return 0;
}