#include "TimeSort.h"
#include <iostream>

int main(){
	/* load array and print it*/
	size_t len = 12;
	double arr[] = {9,8,45,88,95,1,1,1,1,7,3,1};
	for(int i=0; i<len; i++)
		std::cout << arr[i] << ' ';

	/* sort array */
	std::cout << '\n';
	TimeSort(arr,arr + len);

	/* print sorted array */
	for(int i=0; i<len; i++)
		std::cout << arr[i] << ' ';

	

}
