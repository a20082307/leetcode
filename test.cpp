#include <iostream>

using namespace std;

bool binarySearch(int a[], int left, int right, int target) {
    if (left > right)
        return false;

    int mid = (left + right) / 2;
    if (a[mid] == target)
        return true;
    else if (a[mid] > target)
        return binarySearch(a, left, mid - 1, target);
    else
        return binarySearch(a, mid + 1, right, target);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;  cin >> n >> q;
    int* a = new int[n];

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i ++) {
        int target;  cin >> target;
        binarySearch(a, 0, n - 1, target) ? cout << "Yes\n" : cout << "No\n";
    }
}