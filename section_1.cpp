//
// Created by khaint02 on 19/06/25.
//
#include <bits/stdc++.h>
using namespace std;

int a[] = {-2, 11, -4, 13, -5, 2};
int n = 6;

void DuyetToanBo()
{

    int maxSum = a[0];

    for (int i = 0; i<=n-1; i++) {
        int sum = 0;
        for (int j = i; j<n; j++) {
            sum += a[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << "the sum maximum of length number: "<<maxSum<<endl;
}

int maxLeft ( int a[], int low , int mid) {
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}

int maxRight ( int a[], int mid1 , int high) {
    int sum = 0;
    int maxSum = INT_MIN ;
    for (int i = mid1; i <= high; i++) {
        sum += a[i];
        if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}

int maxSub(int a[], int low, int high) {
    if (low == high) return a[low];
    else {
        int mid = (low + high)/ 2;
        int WL = maxSub(a, low, mid);
        int WR = maxSub(a, mid + 1, high);
        int WM = maxLeft(a, low, mid) + maxRight (a, mid + 1, high);
        return max(WL, max(WR, WM));
    }
}

void DeQuy() {
    int result = maxSub(a, 0, n-1);
    cout << "method dequy == " << result << endl;
}

void quyhoachdon() {
    int ei = a[0];
    int si = a[0];
    for (int i = 1; i < n-1; i++) {
        ei = max(a[i], a[i]+ei);
        si = max(si , ei);
    }
    cout << "quy hoach dong " << si << endl;
}

int main() {
    DeQuy();
    DuyetToanBo();
    quyhoachdon();
    return 0;
}
