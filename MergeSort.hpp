/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <vector>
#include <chrono>

// Helper function for recursive merge sort
// Output: Performs in-place merge sort on the sub-vector
void mergeRecursive(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    // Check if the sub-vector has more than one element
    if (high - low > 1) {
        auto mid = low + (high - low) / 2; // Calculate the middle iterator of the sub-vector
        mergeRecursive(nums, low, mid); // Recursively sort the left half of the sub-vector
        mergeRecursive(nums, mid, high); // Recursively sort the right half of the sub-vector

        // Merge the two sorted halves back into the original vector
        std::vector<int> temp(low, high);
        std::merge(low, mid, mid, high, temp.begin());
        std::copy(temp.begin(), temp.end(), low);
    }
}

// Function to perform merge sort on a vector of integers
// Output: Returns the median of the sorted vector
int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now(); // Record the start time for measuring sorting duration

    mergeRecursive(nums, nums.begin(), nums.end()); // Call the recursive merge sort function

    auto end = std::chrono::high_resolution_clock::now(); // Record the end time for measuring sorting duration
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Calculate and store the sorting duration

    size_t medianIndex = nums.size() / 2;
    return nums.size() % 2 == 0 ? nums[medianIndex - 1] : nums[medianIndex]; // Return the median of the sorted vector
}


#endif // MERGE_SORT_HPP
