/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2 - Driver code for testing
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // For timing
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"
#include "MedianOfMediansMethod.hpp"

// Function to read integers from a file into a vector
std::vector<int> readIntegersFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::vector<int> numbers;

    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    return numbers;
}

int main() {
    std::vector<int> originalVector = readIntegersFromFile("input.txt");

    // Create copies of the original vector for each algorithm
    std::vector<int> vectorForSelectionSort = originalVector;
    std::vector<int> vectorForStdSort = originalVector;
    std::vector<int> vectorForMergeSort = originalVector;
    std::vector<int> vectorForInPlaceMergeSort = originalVector;
    std::vector<int> vectorForHeapSort = originalVector;
    std::vector<int> vectorForQuickSelect = originalVector;
    std::vector<int> vectorForWorseQuickSelect = originalVector;
    std::vector<int> vectorForMedianOfMedian = originalVector;
    // Create copies for other algorithms.

    // Variables to hold duration and median for each algorithm
    int durationSelectionSort = 0, durationStdSort = 0, durationMerge = 0, durationInPlaceMerge = 0, durationHeap = 0, durationQuick = 0, durationWorstQuick = 0, durationMedianOfMed = 0;
    int medianSelectionSort, medianStdSort, medianMerge, medianInPlaceMerge, medianHeap, medianQuick, medianWroseQuick, medianMedianOfMed;
    // Variables for other algorithms

   
    auto start = std::chrono::steady_clock::now();
    medianSelectionSort = halfSelectionSort(vectorForSelectionSort, durationSelectionSort);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsedSelectionSort = end - start;

    /*start = std::chrono::steady_clock::now();
    medianStdSort = standardSort(vectorForStdSort, durationStdSort);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsedStdSort = end - start;*/

    // Print results
    std::cout << "Half Selection Sort - Median: " << medianSelectionSort << ", Duration: " << elapsedSelectionSort.count() << "ms\n";
    //std::cout << "Std Sort - Median: " << medianStdSort << ", Duration: " << elapsedStdSort.count() << "ms\n";
    // Print results for other algorithms...

    return 0;
}