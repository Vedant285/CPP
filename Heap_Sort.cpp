#include <bits/stdc++.h>
using namespace std;
class Heap_Sort
{
    void Heap(int arr[], int n, int i)
    {
        int longest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[longest])
            longest = left;
        if (right < n && arr[right] > arr[longest])
            longest = right;
        if (longest != i)
        {
            int t = arr[i];
            arr[i] = arr[longest];
            arr[longest] = t;
            Heap(arr, n, longest);
        }
    }

public:
    void heapSort(int arr[], int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            Heap(arr, n, i);
        }
        for (int j = n - 1; j >= 0; j--)
        {
            int t = arr[0];
            arr[0] = arr[j];
            arr[j] = t;
            Heap(arr, j, 0);
        }
    }
};
int main()
{
    int arr[5] = {55, 76, 22, 73, 12};
    Heap_Sort h;
    h.heapSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << '\t';
    }
}