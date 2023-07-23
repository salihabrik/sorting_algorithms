#include <stdio.h>

 /** shell_sory - my function to sort
 *
 * @array: the array we need to sort
 * @size: size of that array
 */

void shell_sort(int *array, size_t size)
{ /* Generate the Knuth sequence*/
       	int interval = 1;
	while (interval <= (size - 1) / 3)
       	{ interval = interval * 3 + 1; } 
	while (interval > 0)
	{ /* Perform insertion sort with the current interval*/
	       	for (size_t i = interval; i < size; ++i)
	       	{ int temp = array[i];
		       	size_t j = i;
			while (j >= interval && array[j - interval] > temp)
		       	{ array[j] = array[j - interval]; j -= interval; } 
			array[j] = temp; }/* Print the array after each pass*/
	       	for (size_t i = 0; i < size; ++i)
	       	{ printf("%d ", array[i]); }
	       	printf("\n"); /* Update the interval*/
	       	interval = (interval - 1) / 3;
       	} }
