/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef STANDARD_SORT_HPP
#define STANDARD_SORT_HPP
#include <vector>
#include <algorithm>
#include <chrono>

// Function to perform standard sorting on a vector of integers
// Output: Returns the median of the sorted vector
int standardSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now(); // Record the start time for measuring sorting duration

    std::sort(nums.begin(), nums.end()); // Perform standard sorting on the vector

    size_t index = nums.size() / 2; // Calculate the index of the median
    int median = nums[index]; // Retrieve the median value

    //for even vectors
    if (nums.size() % 2 == 0) {
        median = nums[index - 1]; // If the vector size is even, adjust the median value
    }

    auto end = std::chrono::high_resolution_clock::now(); // Record the end time for measuring sorting duration
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count(); // Calculate and store the sorting duration

    return median; // Return the median of the sorted vector
}

#endif // STANDARD_SORT_HPP
