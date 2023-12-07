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

int standardSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(nums.begin(), nums.end());

    size_t medianIndex = nums.size() / 2;
    int median = nums[medianIndex];

    // Adjust for even-sized vector
    if (nums.size() % 2 == 0) {
        median = nums[medianIndex - 1];
    }

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return median;
}

#endif // STANDARD_SORT_HPP
