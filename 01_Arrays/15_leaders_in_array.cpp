#include <iostream>
#include <vector>
using namespace std;

void printLeaders(int arr[], int n) {
    vector<int> leaders;
    int max_from_right = arr[n - 1];
    leaders.push_back(max_from_right); // Last element is always a leader

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }

    cout << "Leaders in the array: ";
    for (int i = leaders.size() - 1; i >= 0; --i)
        cout << leaders[i] << " ";
    
    cout << endl;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printLeaders(arr, n);

    return 0;
}
