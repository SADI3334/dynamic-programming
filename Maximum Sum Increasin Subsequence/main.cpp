#include <bits/stdc++.h>
using namespace std;
int arr[100];
int mx[100];

class MaxSum
{
public:
    void storeMax (int n) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    mx[i] = max(mx[i], mx[j] + arr[i]);
                }
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        mx[i] = arr[i];
    }
    MaxSum m;
    m.storeMax(n);
    cout << *max_element(mx, mx + n) << endl;
    return 0;
}
