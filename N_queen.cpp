#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define pb push_back

bool isSafe(int **arr, int x, int y, int n)
{
    for (ll row = 0; row < x; row++)
    {
        if (arr[row][y] == 1) return false;
    }
    
        int row = x;
        int col = y;
        
        while(row >= 0 and col >= 0)
        {
            if(arr[row][col] == 1) return false;
            row--;
            col--;
        }

    
        row = x;
        col = y;
        while(row >= 0 and col < n)
        {
            if(arr[row][col] == 1) return false;
            row--;
            col++;
        }
    
    return true;
}

bool nQueen(int** arr, int x, int n)
{
    
    if(x >= n) return true;
    
    for(int col = 0 ; col < n ; col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col] = 1;
            if(nQueen(arr,x+1,n)) return true;
        }
        arr[x][col] = 0;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int** arr=new int*[n];
    for (ll i = 0 ; i < n ; i++) 
    {
        arr[i]=new int[n];
        for (ll j = 0 ; j < n ; j++)
        {
            arr[i][j] = 0;
        }
    }

    if(nQueen(arr,0,n))
    {
        for (ll i = 0 ; i < n ; i++) 
        {
            for (ll j = 0 ; j < n ; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}