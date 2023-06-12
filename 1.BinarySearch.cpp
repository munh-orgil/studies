#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int num, int left, int right, vector < int > array) {
    if(left > right) {
        return -1;
    }
    int mid = (left + right) / 2;
    if(array[mid] > num) {
        return BinarySearch(num, left, mid - 1, array);
    } else if(array[mid] < num) {
        return BinarySearch(num, mid + 1, right, array);
    } else {
        return mid;
    }
}

int main() {
    freopen("1.BinarySearch.in", "r", stdin);

    int n;
    cin >> n;
    vector < int > array(n);

    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // only for sorted arrays
    sort(array.begin(), array.end());

    int query;
    cin >> query;

    for(int i = 0; i < query; i++) {
        int num;
        cin >> num;
        int index = BinarySearch(num, 0, n - 1, array);

        cout << "number at index: " << index << endl;
    }
}