# 📁 01_Arrays - Mastering Arrays in C++

This folder contains optimized and tricky C++ programs focused on **array manipulation**, **pointer usage**, and **interview-level logic**. Each program is designed to strengthen your understanding of arrays in C++, with clean and efficient solutions.

---

## 📜 Programs List

### ✅ `01_reverse_array.cpp`
Reverses an array in-place using the **two-pointer** technique.  
💡 *One of the most common interview problems to test your grip on basic array operations.*

---

### ✅ `02_move_zeroes.cpp`
Moves all zeroes to the end of the array **without changing the relative order** of non-zero elements.  
✨ *Implemented using two raw pointers — avoids indexing completely, ideal for understanding low-level manipulation.*

---

### ✅ `03_second_largest.cpp`
Finds the **second largest element** in an array without using `INT_MIN`.  
🔢 *Carefully handles edge cases where elements may be negative or duplicates.*

---

### ✅ `04_remove_duplicates.cpp`
Removes duplicates from a **sorted array** in-place and returns the new length.  
🚫 *Efficient in-place approach using pointer comparisons.*

---

### ✅ `05_left_rotate_d.cpp`
Rotates an array to the **left by D positions** using reversal algorithm.  
🔁 *Optimal in-place solution with O(n) time and O(1) space.*

---

### ✅ `06_sort_012.cpp` – *Dutch National Flag Algorithm*
Sorts an array containing only 0s, 1s, and 2s in a **single pass** using three pointers.  
🎨 *The Dutch National Flag algorithm divides the array into 3 sections:*

- `low` → all 0s  
- `mid` → all 1s  
- `high` → all 2s  

➡️ Elements are swapped in place to maintain these zones in a single traversal.  
🧠 **Time Complexity:** O(n) | **Space:** O(1)

---

### ✅ `07_kadane_max_subarray.cpp` – *Kadane’s Algorithm*
Finds the **maximum subarray sum** efficiently, even when negatives are involved.  
📈 *Instead of checking all subarrays (which takes O(n²)), it maintains a running sum and resets when it goes negative.*

- Let `maxSum = currentSum = arr[0]`  
- For every element:  
  - `currentSum = max(arr[i], currentSum + arr[i])`  
  - `maxSum = max(maxSum, currentSum)`

✨ Simple, fast, and widely used in coding interviews.  
🧠 **Time Complexity:** O(n) | **Space:** O(1)

---
## 🚀 Upcoming Programs (Planned)

- 🔄 Check if array is sorted and rotated
- 🔀 Merge two sorted arrays in-place
- 🔍 Array intersection and union
- 🎯 Subarray with given sum
- 🗳️ Majority element using Boyer-Moore
- 📆 Longest consecutive subsequence
- ➕ Rearranging positive and negative numbers
- 🧠 Leaders in an array

---

> ✨ Stay tuned for more optimized and advanced array-based problems with clear logic and pointer implementations!

