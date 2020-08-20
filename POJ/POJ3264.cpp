#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
int a[100002],b[100002];
int min1[100002][22],max1[100002][22],n,q;

int query(int l,int r){
    if(l>r) return 0;
    int k=(int)(log(r-l+1));
    return max(max1[l][k],max1[r-(1<<k)+1][k]);
}


void rmq(int n){
    int lg=int(log10(n)/log10(2));
    for(int i=1;i<=n;i++) min1[i][0]=max1[i][0]=b[i];
    for(int j=1;j<=lg;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            max1[i][j]=max(max1[i][j-1],max1[i+(1<<(j-1))][j-1]);
        }
    }
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    while(cin>>n&&n){
        cin >> q;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]) b[i]=b[i-1]+1;
            else b[i]=1;
        }
        rmq(n);
        while(q--){
            int t1,t2,t=0;
            cin >> t1>>t2;
            t=t1;
               while(t<=t2&&a[t]==a[t-1]) t++;
                int maxres=query(t,t2);
                maxres=max(maxres,t-t1);
                cout<<maxres<<endl;
            }
    }
    return 0;
}