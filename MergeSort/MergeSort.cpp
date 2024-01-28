#include <iostream>

using namespace std;

void merge(int array[], int size)
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

int arr[] = {1,3,7,8,2,4,5,6,9};
int main()
{
    int size = sizeof(arr) / sizeof(arr[0]);
    int midIndex = size/2-1;
    cout << midIndex << endl;
    merge(arr, size);
    for(int i = 0; i<size; i++)
    {
        cout << arr[i];
    }
    return 0;
}