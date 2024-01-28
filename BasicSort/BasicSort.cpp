#include "iostream"

using namespace std;

int arr[] = {4,2,6,5,1,3};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* array, int size)
{
    for(int i=size; i>0; i--)
    {
        for(int j=0; j<i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void selectionSort(int array[], int size)
{
    int minIndex = 0;
    for(int i=0; i<size-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(array[minIndex] > array[j])
                minIndex = j;
        }
        if(i != minIndex)
            swap(&array[i], &array[minIndex]);
    }
}

void my_insertionSort(int array[], int size)
{
    for(int i=1; i<size; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(array[j-1] > array[j])
            {
                swap(&array[j], &array[j-1]);
            }
            else
            {
                break;
            }
        }
    }
}

void insertionSort(int array[], int size)
{
    for(int i=1; i<size; i++)
    {
        int temp = array[i];
        int j=i-1;
        while(j>=0 && temp < array[j])
        {
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}
int main()
{
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}