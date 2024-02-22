#include <iostream>

using namespace std;

int arr[] = {4, 6, 1, 7,3,2,5};

//dua pivotIndex ve dung cho sau khi sort
int pivot(int array[], int pivotIndex, int endIndex)
{
    // Initialize the index of the last element smaller than pivot to pivotIndex
    int swapIndex = pivotIndex;
    
    // Iterate over the elements after pivotIndex
    for(int i=pivotIndex+1; i<=endIndex; i++)
    {
        // If the current element is smaller than the pivot element, move it
        // to the left partition by swapping it with the element at swapIndex
        if(array[i] < array[pivotIndex])
        {
            swapIndex++;
            int temp = array[i];
            array[i] = array[swapIndex];
            array[swapIndex] = temp;
        }
    }
    // Swap the pivot element with the last element smaller than the pivot
    int temp = array[pivotIndex];
    array[pivotIndex] = array[swapIndex];
    array[swapIndex] = temp;
    // Return the index of the pivot element
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) 
{
    if(leftIndex >= rightIndex) return;
    quickSort(array, leftIndex, pivot(array, leftIndex, rightIndex) - 1);
    quickSort(array, pivot(array, leftIndex, rightIndex) + 1, rightIndex);
}

int main()
{

    quickSort(arr,0,6);
    for(int i=0; i<7; i++)
    {
        cout << arr[i];
    }
    return 0;
}