#include <iostream>

using namespace std;

void mymerge(int array[], int size)
{
    if(size < 2) return;

    //calculate left and right arr size
    int leftArraySize = size / 2;
    int rightArraySize = size - leftArraySize;

    //creat temp left right arr
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    //copy element to left and righ arr
    for(int i=0; i<leftArraySize; i++)
    {
        leftArray[i] = array[i];
    }
    for(int i=0; i<rightArraySize; i++)
    {
        rightArray[i] = array[i+leftArraySize];
    }

    int index = 0;
    int i = 0;
    int j = 0;

    while(i<leftArraySize && j < rightArraySize)
    {
        if(leftArray[i] < rightArray[j])
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }
    for(i; i<leftArraySize; i++)
    {
        array[index] = leftArray[i];
        index++;
    }
    for(j; j<rightArraySize; j++)
    {
        array[index] = rightArray[i];
        index++;
    }
}

void merge(int array[], int leftIndex, int midIndex, int rightIndex) 
{
    //calculate left and right arr size
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    //creat temp left and right arr
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    //copy element to left and righ arr
    for(int i = 0; i< leftArraySize; i++)
    {
        leftArray[i] = array[i+leftIndex];
    }
    for(int i = 0; i<rightArraySize; i++)
    {
        rightArray[i] = array[i+midIndex+1];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;

    //merge the elements from leftArray and rightArray
    //into the original array in sorted order
    while(i<leftArraySize && j < rightArraySize)
    {
        if(leftArray[i] < rightArray[j])
        {
            array[index] = leftArray[i];
            i++;
            index++;
        }
        else
        {
            array[index] = rightArray[j];
            j++;
            index++;
        }
    }

    //Copy the remaining elements from the left subarray or right subarray
    for(i; i<leftArraySize; i++)
    {
        array[index] = leftArray[i];
        index++;
    }
    for(j; j<rightArraySize; j++)
    {
        array[index] = rightArray[j];
        index++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex) return;
    int mid = (rightIndex + leftIndex)/2;
    mergeSort(array, leftIndex, mid);
    mergeSort(array, mid+1, rightIndex);
    merge(array, leftIndex, mid, rightIndex);
}

int arr[] = {1,3,7,8,2,4,5,6,9};
// Utility function to compare two arrays for equality
bool areArraysEqual(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void printArray(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    // EmptyArray test
    {
        cout << "\n----- Test: EmptyArray -----\n";
        int arr[] = {};
        int expected[] = {};
        cout << "Original Array: "; printArray(arr, 0); cout << "\n";
        mergeSort(arr, 0, -1);
        cout << "EXPECTED: "; printArray(expected, 0); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 0); cout << "\n";
        cout << (areArraysEqual(arr, expected, 0) ? "PASS\n" : "FAIL\n");
    }

    // SingleElementArray test
    {
        cout << "\n----- Test: SingleElementArray -----\n";
        int arr[] = {42};
        int expected[] = {42};
        cout << "Original Array: "; printArray(arr, 1); cout << "\n";
        mergeSort(arr, 0, 0);
        cout << "EXPECTED: "; printArray(expected, 1); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 1); cout << "\n";
        cout << (areArraysEqual(arr, expected, 1) ? "PASS\n" : "FAIL\n");
    }

    // AlreadySortedArray test
    {
        cout << "\n----- Test: AlreadySortedArray -----\n";
        int arr[] = {1, 2, 3, 4, 5};
        int expected[] = {1, 2, 3, 4, 5};
        cout << "Original Array: "; printArray(arr, 5); cout << "\n";
        mergeSort(arr, 0, 4);
        cout << "EXPECTED: "; printArray(expected, 5); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 5); cout << "\n";
        cout << (areArraysEqual(arr, expected, 5) ? "PASS\n" : "FAIL\n");
    }

    // ReverseSortedArray test
    {
        cout << "\n----- Test: ReverseSortedArray -----\n";
        int arr[] = {5, 4, 3, 2, 1};
        int expected[] = {1, 2, 3, 4, 5};
        cout << "Original Array: "; printArray(arr, 5); cout << "\n";
        mergeSort(arr, 0, 4);
        cout << "EXPECTED: "; printArray(expected, 5); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 5); cout << "\n";
        cout << (areArraysEqual(arr, expected, 5) ? "PASS\n" : "FAIL\n");
    }

    // RandomArray test
    {
        cout << "\n----- Test: RandomArray -----\n";
        int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        int expected[] = {1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9};
        cout << "Original Array: "; printArray(arr, 11); cout << "\n";
        mergeSort(arr, 0, 10);
        cout << "EXPECTED: "; printArray(expected, 11); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 11); cout << "\n";
        cout << (areArraysEqual(arr, expected, 11) ? "PASS\n" : "FAIL\n");
    }

    // DuplicatesArray test
    {
        cout << "\n----- Test: DuplicatesArray -----\n";
        int arr[] = {3, 3, 3, 1, 2, 2, 2};
        int expected[] = {1, 2, 2, 2, 3, 3, 3};
        cout << "Original Array: "; printArray(arr, 7); cout << "\n";
        mergeSort(arr, 0, 6);
        cout << "EXPECTED: "; printArray(expected, 7); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 7); cout << "\n";
        cout << (areArraysEqual(arr, expected, 7) ? "PASS\n" : "FAIL\n");
    }

    // LargeSizeArray test
    {
        cout << "\n----- Test: LargeSizeArray -----\n";
        const int SIZE = 1000;
        int arr[SIZE];
        int expected[SIZE];
        for (int i = 0; i < SIZE; i++) {
            arr[i] = SIZE - i;
            expected[i] = i + 1;
        }
        cout << "Array: SIZE 1000" << "\n";
        mergeSort(arr, 0, SIZE - 1);
        // cout << "EXPECTED: "; printArray(expected, SIZE); cout << "\n";
        // cout << "RETURNED: "; printArray(arr, SIZE); cout << "\n";
        cout << (areArraysEqual(arr, expected, SIZE) ? "PASS\n" : "FAIL\n");
    }

    // NegativeNumbersArray test
    {
        cout << "\n----- Test: NegativeNumbersArray -----\n";
        int arr[] = {3, -1, 4, -5, 6, -2};
        int expected[] = {-5, -2, -1, 3, 4, 6};
        cout << "Original Array: "; printArray(arr, 6); cout << "\n";
        mergeSort(arr, 0, 5);
        cout << "EXPECTED: "; printArray(expected, 6); cout << "\n";
        cout << "RETURNED: "; printArray(arr, 6); cout << "\n";
        cout << (areArraysEqual(arr, expected, 6) ? "PASS\n" : "FAIL\n");
    }
}
