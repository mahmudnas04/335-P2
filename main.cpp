/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2 - Driver code for testing
*/

#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"
#include "MedianOfMediansMethod.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono> // For timing

std::vector<int> readFile(const std::string& filename)
{
    std::vector<int> input; // Initialize vector to store integers from the file
    std::ifstream inputFile(filename);   // Open the file for reading
    if(!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << filename <<std::endl; // Print an error message if file opening fails
        return input; // Return the empty vector
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int num;
        while(iss >> num)
        {
            input.push_back(num); // Parse each integer from the line and add it to the vector
        }
    }
    inputFile.close(); // Close the file after reading
    return input; // Return the vector containing integers from the file
}

void vectorPrinter(std::vector<int> vector)
{
    for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << " "; // Print each element of the vector
    }
}

int main()
{
    int num = 0;
    std::cout<<"select input file\n";
    std::string filename;
    std::cin>> filename;
    std::vector<int> test = readFile(filename); // Read integers from the file and store them in a vector
    std::cout << "Median before sort: " << test.at((test.size()+1)/2) <<std::endl; // Print the median before sorting
    vectorPrinter(test); // Print the elements of the vector

    
    std::cout << "\n\nSorting with Standard sort\n";
    std::cout<< "median: "<< standardSort(test, num) <<std::endl;
    vectorPrinter(test);
    
    

    
    std::cout << "\n\nSorting with half selection sort\n";
    std::cout<< "median: "<< halfSelectionSort(test, num) <<std::endl;
    vectorPrinter(test);
    
    
    
    std::cout << "\n\nSorting with merge sort\n";
    std::cout<< "median: "<< mergeSort(test, num) <<std::endl; // Print the median after sorting with merge sort
    vectorPrinter(test); // Print the elements of the vector after sorting

    std::cout << "\n\nSorting with Inplace merge sort\n";
    std::cout<< "median: "<< inPlaceMergeSort(test, num) <<std::endl; // Print the median after sorting with merge sort
    vectorPrinter(test); // Print the elements of the vector after sorting
}
