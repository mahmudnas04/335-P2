/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef IN_PLACE_MERGE_SORT_HPP
#define IN_PLACE_MERGE_SORT_HPP

#include <vector>
#include <algorithm>
#include <chrono>

// Helper function for recursive in-place merge sort
void inPlaceMergeRecursive(std::vector<int>& nums, std::vector<int>::iterator begin, std::vector<int>::iterator end, int& duration) {
    // Check if the sub-vector has more than one element
    if (end - begin > 1) {
        auto mid = begin + (end - begin) / 2; // Calculate the middle iterator of the sub-vector

        // Recursively sort the left half of the sub-vector
        inPlaceMergeRecursive(nums, begin, mid, duration);

        // Recursively sort the right half of the sub-vector
        inPlaceMergeRecursive(nums, mid, end, duration);

        // Merge the two sorted halves back into the original vector in-place
        std::inplace_merge(begin, mid, end);
    }
}

// Function to perform in-place merge sort on a vector of integers
// Output: Returns the median of the sorted vector
int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now(); // Record the start time for measuring sorting duration

    // Call the recursive helper function to perform in-place merge sort
    inPlaceMergeRecursive(nums, nums.begin(), nums.end(), duration);

    auto end_time = std::chrono::high_resolution_clock::now(); // Record the end time for measuring sorting duration
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start).count(); // Calculate and store the sorting duration

    size_t medianIndex = nums.size() / 2;
    return nums.size() % 2 == 0 ? nums[medianIndex - 1] : nums[medianIndex]; // Return the median of the sorted vector
}

/*
// Function to perform in-place merge sort on a vector of integers
int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now(); //start time

    // Perform in-place merge sort using std::inplace_merge
    std::vector<int>::iterator begin = nums.begin();
    std::vector<int>::iterator end = nums.end();
    std::inplace_merge(begin, begin + (end - begin) / 2, end);  //pass arguments

    auto end_time = std::chrono::high_resolution_clock::now(); //end time
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start).count(); // Calculate and store the sorting duration

    size_t medianIndex = nums.size() / 2;
    return nums.size() % 2 == 0 ? nums[medianIndex - 1] : nums[medianIndex]; // Return the median of the sorted vector
}
*/

#endif // IN_PLACE_MERGE_SORT_HPP

