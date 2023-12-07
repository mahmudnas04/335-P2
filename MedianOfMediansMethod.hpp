/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef MEDIAN_OF_MEDIANS_METHOD_HPP
#define MEDIAN_OF_MEDIANS_METHOD_HPP

#include <vector>

int medianOfMediansMethod(std::vector<int>& nums, int& duration);
int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
int medianOfFive(int a, int b, int c, int d, int e);

#endif // MEDIAN_OF_MEDIANS_METHOD_HPP
