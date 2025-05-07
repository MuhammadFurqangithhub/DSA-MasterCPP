# 📁 01_Arrays - Mastering Arrays in C++

This folder contains 15 optimized and tricky C++ programs focused on **array manipulation**, **pointer usage**, and **interview-level logic**. Each program is clean, readable, and written with performance and clarity in mind.

---

## 📜 Programs List

### ✅ `01_reverse_array.cpp`
Reverses an array in-place using the **two-pointer** technique.  
💡 *Tests your grip on basic array operations and in-place manipulation.*

---

### ✅ `02_move_zeroes.cpp`
Moves all zeroes to the end of the array **without changing the relative order** of non-zero elements.  
✨ *Implemented using two raw pointers — ideal for learning low-level pointer logic.*

---

### ✅ `03_second_largest.cpp`
Finds the second largest element in the array using a **single traversal**.  
🚀 *No sorting or extra space used.*

---

### ✅ `04_remove_duplicates_sorted.cpp`
Removes duplicates from a sorted array **in-place**, returns the new length.  
🧹 *Two-pointer approach simulates `std::unique` behavior.*

---

### ✅ `05_left_rotate_d_positions.cpp`
Left rotates an array by D positions using the **reversal algorithm**.  
🔁 *Efficient, in-place, and O(n) time complexity.*

---

### ✅ `06_sort_0s_1s_2s.cpp`  
Implements the **Dutch National Flag Algorithm** to sort 0s, 1s, and 2s in a single traversal.  
🎨 *Dijkstra’s three-way partitioning approach for linear sorting.*

🔍 **About the Dutch National Flag Algorithm:**  
It partitions the array into three sections: `<pivot`, `=pivot`, and `>pivot`. Ideal for problems like sorting colors or partitioning elements efficiently.

---

### ✅ `07_kadane_max_subarray.cpp`
Finds the maximum subarray sum using **Kadane's Algorithm**.  
📈 *A dynamic programming approach with linear time.*

🧠 **Kadane’s Algorithm Explained:**  
At each index, decide whether to include the current element in the previous subarray or start a new one. Track the maximum encountered so far.

---

### ✅ `08_check_sorted_rotated.cpp`
Checks if the given array is **sorted and rotated**.  
🔄 *Counts the number of sorted violations — only one is allowed for valid rotation.*

---

### ✅ `09_merge_sorted_arrays.cpp`
Merges two sorted arrays **in-place** without using extra space.  
⚔️ *Uses the Gap method (Shell Sort concept) to reduce comparisons.*

---

### ✅ `10_intersection_union.cpp`
Finds **intersection and union** of two arrays using hashing.  
📊 *Demonstrates use of `unordered_set` for O(n) average complexity.*

---

### ✅ `11_subarray_given_sum.cpp`
Finds a **continuous subarray** that adds up to a given sum (for positive integers).  
🎯 *Sliding window approach, O(n) time.*

---

### ✅ `12_majority_element.cpp`
Finds the **majority element** using Boyer-Moore Voting Algorithm.  
🗳️ *O(n) time and O(1) space — optimal and elegant solution.*

---

### ✅ `13_longest_consecutive_subsequence.cpp`
Finds the **length of the longest consecutive subsequence**.  
📆 *Uses hashing for O(n) performance.*

---

### ✅ `14_rearrange_pos_neg.cpp`
Rearranges array such that **positive and negative numbers alternate**, maintaining order.  
➕ *Uses separate temp arrays and merges while maintaining position.*

---

### ✅ `15_leaders_in_array.cpp`
Finds all **leaders** in an array — an element is a leader if it's greater than all elements to its right.  
👑 *Reverse traversal, no nested loops. O(n) efficient.*

---

## 🏁 Summary

| #   | Program                            | Techniques Used                     |
|-----|------------------------------------|-------------------------------------|
| 01  | Reverse Array                      | Two-pointer                         |
| 02  | Move Zeroes                        | Pointer Manipulation                |
| 03  | Second Largest                     | Single Pass, No Sorting             |
| 04  | Remove Duplicates (Sorted)         | Two Pointers                        |
| 05  | Left Rotate by D                   | Reversal Algorithm                  |
| 06  | Sort 0s, 1s, 2s                    | Dutch National Flag                 |
| 07  | Maximum Subarray Sum               | Kadane’s Algorithm (DP)             |
| 08  | Sorted & Rotated Check             | Count Violations                    |
| 09  | Merge Sorted Arrays In-place       | Gap Method                          |
| 10  | Intersection & Union               | Hashing                             |
| 11  | Subarray with Given Sum            | Sliding Window                      |
| 12  | Majority Element                   | Boyer-Moore                         |
| 13  | Longest Consecutive Subsequence    | Hashing                             |
| 14  | Rearranging Pos/Neg                | Temp Arrays + Merge Logic           |
| 15  | Leaders in Array                   | Reverse Traversal, O(n)             |

---

> 🚀 *Keep exploring, commit consistently, and watch your array mastery level up!*

