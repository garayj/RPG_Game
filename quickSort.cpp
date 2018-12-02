/**************************************************************************************************
** Author: Jose Garay
** Date: 11/17/2018
** Description: The quickSort function takes a vector pointer and two integers as input. Utilizes
the partition method as well as a recursive call to itself to split the array into smaller arrays 
and sort each integer in the array into their proper position in the array. The two integers are
used to represent the lowest index and the highest index in the array.
**************************************************************************************************/
#include "quickSort.hpp"

/**************************************************************************************************
** Credit: The quickSort function was found on the lecture pdf slides.
**************************************************************************************************/
void quickSort(std::vector<Character*> *array, int low, int high){
	if(low >= high){
		return;
	}
	int j = partition(array, low, high);
	quickSort(array, low, j);
	quickSort(array, j + 1, high);
}

/**************************************************************************************************
** Description: The partition method takes a pointer to a vector of integer type and two integers
as input. The vector is passed by reference and the low and high integers are used as the upper and
lower limits of the partition the algorithm is analyzing. A pivot between the upper and lower limit
is chosen and the algorithm checks the array between the two indices and places all the integers 
that are lower than the pivot to the left and all the integers that are higher than the pivot, to 
the right. Once that process is done, The algorithm finds the correct index of the pivot value.
**************************************************************************************************/
/**************************************************************************************************
** Credit: The partition function was found on the lecture pdf slides.
**************************************************************************************************/
int partition(std::vector<Character*> *arr, int low, int high){
	int pivot = (*arr)[(low + high)/2]->getSpeed();
	int i = low - 1;
	int j = high + 1;
	while(i < j){
		i++;
		while((*arr)[i]->getSpeed() < pivot){
			i++;
		}
		j--;
		while((*arr)[j]->getSpeed() > pivot){
			j--;
		}
		if(i < j){
			Character *temp = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = temp;
		}
	}
	return j;
}
