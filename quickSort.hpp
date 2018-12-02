/**************************************************************************************************
** Author: Jose Garay
** Date: 12/01/2018
** Description: The quickSort function takes a vector pointer and two integers as input. Utilizes
the partition method as well as a recursive call to itself to split the array into smaller arrays 
and sort each Character in the array into their proper position in the array. The two integers are
used to represent the lowest index and the highest index in the array. The Characters are sorted 
by their speed rating.
**************************************************************************************************/
#ifndef QUICKSEARCH_HPP
#define QUICKSEARCH_HPP 
#include "Character.hpp"
/**************************************************************************************************
** Credit: The quickSort function was found on the lecture pdf slides.
**************************************************************************************************/
#include <vector>
void quickSort(std::vector<Character*>*, int, int);
int partition(std::vector<Character*>*,int,int);
#endif