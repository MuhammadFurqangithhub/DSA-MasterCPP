#include <iostream>
using namespace std;

// Move all zeroes to end using pointer logic
void moveZeroes(int* arr, int n) 
{
    int* write = arr;       // Pointer to place next non-zero
    int* read = arr;        // Pointer to iterate through array

    // First pass: move non-zero elements to front
    while (read < arr + n) 
    {
        if (*read != 0) 
        {
            *write = *read;
            ++write;
        }
        ++read;
    }

    // Second pass: fill the rest with zeros
    while (write < arr + n) 
    {
        *write = 0;
        ++write;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; ++i)
        cout << *(arr + i) << " ";

    return 0;
}
