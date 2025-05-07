#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

void printUnion(int arr1[], int arr2[], int n, int m) {
    unordered_set<int> us;
    cout << "Union: ";
    for (int i = 0; i < n; i++)
        us.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        us.insert(arr2[i]);

    for (auto x : us)
        cout << x << " ";
    cout << endl;
}

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> freq;
    cout << "Intersection: ";
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;

    for (int i = 0; i < m; i++) {
        if (freq[arr2[i]] > 0) {
            cout << arr2[i] << " ";
            freq[arr2[i]] = 0; // Avoid printing duplicates
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    printUnion(arr1, arr2, n, m);
    printIntersection(arr1, arr2, n, m);

    return 0;
}
