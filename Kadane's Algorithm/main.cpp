#include <bits/stdc++.h>
using namespace std;

#define	watch(x);                 cout << "\n" <<  #x << " is: " << x << "\n";
#define	from(i, n);               for(int i = 0; i < n; ++i)
#define	show(container);          for(auto it = container.begin(); it != container.end(); ++it) { cout << *it << " "; cout << "\n"; }
typedef long long ll;

/// THIS ALGORITHM FINDS THE MAXIMUM SUM BETWEEN ALL POSSIBLE THE SUB-ARRAYS.
/// Two cases to consider.
/// Kadane's Algorithms works if there exists at least one non negative integer in the array.
/// So, we have to check the array once to be sure if all the elements are negative or not.

int MSS(int arr[], int n) {
    /// Checking if all the elements are negative or not.
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        ans = max(ans, arr[i]);
    }
    if (ans < 0) {
        return ans;
    }

    /// If at least one non negative integer exists.
    ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + arr[i] > 0) {
            sum += arr[i];
            watch(sum);
        }
        else {
            sum = 0;
            watch(sum);
        }
        ans = max(ans, sum);
        watch(ans);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int arr[] = {-4, -2, -5, -7, -6, -4, 0, -9};
    cout << MSS(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
