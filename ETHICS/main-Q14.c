#include <stdio.h>
void delete_duplicate(int arr[], int n)
{
    	// Return, if array is empty or contains a single
	// element
	if (n == 0 || n == 1)
		printf("%d", n);

	int temp[n];

	// Start traversing elements
	int j = 0;
	// If current element is not equal to next element
	// then store that current element
	for (int i = 0; i < n - 1; i++)
		if (arr[i] != arr[i + 1])
			temp[j++] = arr[i];

	// Store the last element as whether it is unique or
	// repeated, it hasn't stored previously
	temp[j++] = arr[n - 1];

	// Modify original array
	for (int i = 0; i < j; i++)
		arr[i] = temp[i];
		
    for (int i = 0; i < n; i++)
		printf("%d ", temp[i]);

}
int main()
{
int n;
printf("\n Enter the array size ");
scanf("%d", &n);
int array[n];
int i;
printf("\n Enter the array values ");
for (i = 0; i < n; i++)
{
scanf("%d", &array[i]);
}
printf("\nArray value before removing duplicate ");
// Please add your code Here
printf("\nArray value after removing duplicate ");
delete_duplicate(array, n);
//print the array without duplicates

// Please add your code Here
return 0;
}