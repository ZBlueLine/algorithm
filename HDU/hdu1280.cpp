//堆模板题

#include <iostream>
#include <cstring>
using namespace std;

int a[3010];
int heap[5000000];
int cnt = 0;

void Push(int a)
{
    ++cnt;
    int pos = cnt;
    while((pos>>1)>0&&heap[pos>>1]<a)
    {
        heap[pos] = heap[pos>>1];
        pos = pos>>1;
    }
    heap[pos] = a;
}

int Pop()
{
    int ans = heap[1];
    int lit = heap[cnt];
    heap[cnt] = 0;
    --cnt;
    int pos = 1;
    while((pos<<1)<5000000&&(lit<heap[pos<<1]||lit<heap[pos<<1|1]))
    {
        if(heap[pos<<1]<heap[pos<<1|1])
        {
            heap[pos] = heap[pos<<1|1];
            pos = pos<<1|1;
        }
        else 
        {
            heap[pos] = heap[pos<<1];
            pos = pos<<1;   
        }  
    }
    heap[pos] = lit;
    return ans;
}

int main ()
{
    int N, M;
    while(cin >> N>>M)
    {
        memset(heap, 0, sizeof(heap));
        cnt = 0;
        for(int i = 0; i < N; ++i)
            cin >> a[i];
        for(int i = 0; i < N; ++i)
            for(int j = i+1; j < N; ++j)
                Push(a[i]+a[j]);
        cout <<Pop();
        for(int i = 0; i < M-1; ++i)
        {
            cout <<' '<<Pop();
        }
        cout <<endl;
    }
    return 0;
}
