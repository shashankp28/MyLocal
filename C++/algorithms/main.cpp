#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

using namespace std;

// Is sorted
template <typename T>
bool isSorted(vector<T> &array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

// void bubbleSort(vector<T> &array);
template <typename T>
void bubbleSort(vector<T> &array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
        {
            break;
        }
    }
}

// void selectionSort(vector<T> &array);
template <typename T>
void selectionSort(vector<T> &array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] > array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}

// void insertionSort(vector<T> &array);

// void mergeSort(vector<T> &array);

// void quickSort(vector<T> &array);

// void heapSort(vector<T> &array);

// void shellSort(vector<T> &array);

// void treeSort(vector<T> &array);

int main()
{
    const int n = 20000; // ⚠️ keep smaller for bubble/insertion sort
    vector<int> arr(n);

    // Fill with random numbers
    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(1, n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = dist(rng);
    }

    // --- Bubble Sort ---
    {
        vector<int> copy = arr;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(copy);
        auto end = chrono::high_resolution_clock::now();
        assert(isSorted(copy));
        chrono::duration<double> duration = end - start;
        cout << "Bubble sort on " << n << " elements took "
             << duration.count() << " seconds." << endl;
    }

    // --- Selection Sort ---
    {
        vector<int> copy = arr;
        auto start = chrono::high_resolution_clock::now();
        selectionSort(copy);
        auto end = chrono::high_resolution_clock::now();
        assert(isSorted(copy));
        chrono::duration<double> duration = end - start;
        cout << "Selection sort on " << n << " elements took "
             << duration.count() << " seconds." << endl;
    }

    // --- std::sort (for comparison) ---
    {
        vector<int> copy = arr;
        auto start = chrono::high_resolution_clock::now();
        sort(copy.begin(), copy.end());
        auto end = chrono::high_resolution_clock::now();
        assert(isSorted(copy));
        chrono::duration<double> duration = end - start;
        cout << "std::sort on " << n << " elements took "
             << duration.count() << " seconds." << endl;
    }

    return 0;
}