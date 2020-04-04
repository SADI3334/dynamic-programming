#include <bits/stdc++.h>
using namespace std;
int arr[100];
int sub[100];

class LIS
{
public:
    void process(int n) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    sub[i] = max(sub[i], sub[j] + 1);
                }
            }
        }

    }
};
int main()
{

    int n;
    cin >> n;
    memset (sub, 1, sizeof (sub));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sub[i] = 1;
    }
    LIS seq;
    seq.process(n);
    cout << *max_element(sub, sub + n) << endl;
    return 0;
}
