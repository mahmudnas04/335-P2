/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef HALF_HEAP_SORT_HPP
#define HALF_HEAP_SORT_HPP

#include <vector>

int halfHeapSort(std::vector<int>& nums, int& duration);
void percDown(std::vector<int>& heap, std::vector<int>::size_type hole);
void buildHeap(std::vector<int>& heap);

#endif // HALF_HEAP_SORT_HPP
