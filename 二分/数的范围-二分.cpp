#include <iostream>
using namespace std;
int main ()
{
	int n,t;
    cin >>n>>t;
    int arr[n];
    for (int i = 0;i<n;i++)
        cin >>arr[i];
    while (t--){
        int x;
        cin >>x;
        int i,j=n-1,findl = 0,findr=0;
        for (i = 0;i<=j;i++){
            if (arr[i]==x){
                findl = 1;
                break;
            }
        }
        for (;j>=0;j--){
            if (arr[j]==x){
                findr=1;
                break;
            }
        }
        if (findl&&findr)
            cout <<i <<" " <<j <<endl;
        else
            cout <<"-1 -1" <<endl;
        
    }
	return 0;
}