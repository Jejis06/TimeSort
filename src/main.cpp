#include "TimeSort.h"
#include <iostream>

int main(){
	/* load array and print it*/
	double arr[] = {9,8,45,88,95,1,1,1,1,7,3,1};
	for(int i=0; i<12; i++)
		std::cout << arr[i] << ' ';

	/* sort array */
	TimeSort(arr,12);

	/* print sorted array */
	for(int i=0; i<12; i++)
		std::cout << arr[i] << ' ';

	

}
