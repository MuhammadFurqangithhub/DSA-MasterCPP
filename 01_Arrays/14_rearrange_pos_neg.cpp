#include <iostream>
#include <vector>
using namespace std;

void rearrangePosNeg(int arr[], int n) {
    vector<int> pos, neg;

    // Separate positive and negative numbers
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int i = 0, p = 0, q = 0;

    // Fill alternating positions
    while (p < pos.size() && q < neg.size()) {
        arr[i++] = pos[p++];
        arr[i++] = neg[q++];
    }

    // Fill remaining positives
    while (p < pos.size())
        arr[i++] = pos[p++];

    // Fill remaining negatives
    while (q < neg.size())
        arr[i++] = neg[q++];
}

int main() {
    int arr[] = {2, 3, -4, -1, 6, -9, -7, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrangePosNeg(arr, n);

    cout << "Rearranged array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
