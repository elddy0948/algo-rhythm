#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr, const int left, const int mid, const int right)
{
    const auto leftArraySize = mid - left + 1;
    const auto rightArraySize = right - mid;

    auto* leftArray = new int[leftArraySize];
    auto* rightArray = new int[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = arr[left + i];

    for (int i = 0; i < rightArraySize; i++)
        rightArray[i] = arr[mid + 1 + i];

    auto leftArrayIndex = 0;
    auto rightArrayIndex = 0;
    int mergedIndex = left;

    while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize)
    {
        if (leftArray[leftArrayIndex] <= rightArray[rightArrayIndex])
        {
            arr[mergedIndex] = leftArray[leftArrayIndex];
            leftArrayIndex++;
        }
        else
        {
            arr[mergedIndex] = rightArray[rightArrayIndex];
            rightArrayIndex++;
        }

        mergedIndex++;
    }

    // copy remain left
    while (leftArrayIndex < leftArraySize)
    {
        arr[mergedIndex] = leftArray[leftArrayIndex];
        leftArrayIndex++;
        mergedIndex++;
    }

    // copy remain right
    while (rightArrayIndex < rightArraySize)
    {
        arr[mergedIndex] = rightArray[rightArrayIndex];
        rightArrayIndex++;
        mergedIndex++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(vector<int>& arr, const int begin, const int end)
{
    if (begin >= end)
    {
        return;
    }

    auto mid = begin + (end - begin) / 2;

    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, begin, mid, end);
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    mergeSort(numbers, 0, n - 1);

    for (const auto n : numbers)
        cout << n << '\n';

    return 0;
}