/*
Arif Mahmud Nasif
CSCI 335
arif.nasif25@myhunter.cuny.edu
Assignment 2
*/
#ifndef QUICK_SELECT_HPP
#define QUICK_SELECT_HPP

#include <vector>

int quickSelect(std::vector<int>& nums, int& duration);
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

#endif // QUICK_SELECT_HPP
