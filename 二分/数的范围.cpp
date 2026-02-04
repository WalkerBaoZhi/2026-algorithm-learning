#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (t--)
    {
        int x;
        cin >> x;
        int l = 0, r = n-1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (arr[mid] < x)
                l = mid+1;
            else
                r = mid;
        }
        if (arr[l] != x)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        int l1 = l, r1 = n;
        while (l1 + 1 < r1)
        {
            int mid = (l1 + r1) / 2;
            if (arr[mid] <= x)
                l1 = mid;
            else
                r1 = mid;
        }
        cout << l << " " <<l1<<endl;
    }
    return 0;
}