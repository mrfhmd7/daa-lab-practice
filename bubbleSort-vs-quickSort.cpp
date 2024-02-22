#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int n = 10000;

void BubbleSort(int *a, int num)
{
    int temp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int Partition(int *a, int p, int q)
{
    int pov = a[q];
    int i = p - 1;
    int temp;
    for (int j = p; j <= q - 1; j++)
    {
        if (a[j] <= pov)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[q];
    a[q] = temp;
    return i + 1;
}

void QuickSort(int *a, int i, int j)
{
    if (i < j)
    {
        int m = Partition(a, i, j);
        QuickSort(a, i, m - 1);
        QuickSort(a, m + 1, j);
    }
}

int main()
{
    clock_t start, stop;
    int *array_1 = new int[n];
    for (int i = 0; i < n; array_1[i] = rand(), i++);

    start = clock();
    BubbleSort(array_1, n);
    stop = clock();

    cout << "For " << n << " elements" << endl
         << "Bubble Sort: " << ((double)(stop - start)) / CLOCKS_PER_SEC << " seconds";

    start = clock();
    QuickSort(array_1, 0, n - 1);
    stop = clock();

    cout << endl
         << "Quick Sort: " << ((double)(stop - start)) / CLOCKS_PER_SEC << " seconds";

    delete[] array_1;

    return 0;
}
