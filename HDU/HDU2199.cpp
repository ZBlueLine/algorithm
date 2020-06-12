#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;

double cal(double x, double y)
{return 8*pow(x, 4)+7*pow(x, 3)+2*pow(x,2)+3*x+6-y;}

void find(int y)
{
    double l = 0;
    double r = 100;
    double mid;
    double res;
    if(cal(0, y)>0||cal(100, y)<0)
    {
        cout <<"No solution!"<<endl;
        return;
    }
    while(r-l>=1e-8)
    {
        mid = (l+r)/2;
        res = cal(mid, y);
        if(res > 0)
            r = mid;
        else
            l = mid;
    }
    cout <<fixed<< setprecision(4)<<mid<<endl;
}

int main()
{
    double Y;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> Y;
        find(Y);
    }
    return 0;
}