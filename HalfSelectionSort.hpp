/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef HALF_SELECTION_SORT_HPP
#define HALF_SELECTION_SORT_HPP
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    // Check if input is too big
    if (nums.size() > 50000) {
        std::cout << "Input is too big for selection sort (>50,000 elements)." << std::endl;
        duration = 0;
        return -1; // Indicate failure
    }

    // Iterate through the list to find the median
    for (auto it = nums.begin(); it != nums.begin() + nums.size() / 2; ++it) {
        auto minElement = std::min_element(it, nums.end());

        // Swap the smallest element into its proper place
        std::iter_swap(it, minElement);
    }

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    // Return the lesser of the two middle elements for even-sized lists
    if (nums.size() % 2 == 0) {
        auto middle1 = nums.begin() + nums.size() / 2 - 1;
        auto middle2 = nums.begin() + nums.size() / 2;
        return std::min(*middle1, *middle2);
    } else {
        return *(nums.begin() + nums.size() / 2); // Return the median element for odd-sized lists
    }
}


#endif // HALF_SELECTION_SORT_HPP
