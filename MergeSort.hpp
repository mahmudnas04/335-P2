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
void mergeSortRecursive(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 1) {
        auto mid = low + (high - low) / 2;
        mergeSortRecursive(nums, low, mid);
        mergeSortRecursive(nums, mid, high);
        std::vector<int> temp(low, high);
        std::merge(low, mid, mid, high, temp.begin());
        std::copy(temp.begin(), temp.end(), low);
    }
}

int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    mergeSortRecursive(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    size_t medianIndex = nums.size() / 2;
    return nums.size() % 2 == 0 ? nums[medianIndex - 1] : nums[medianIndex];
}

#endif // MERGE_SORT_HPP
