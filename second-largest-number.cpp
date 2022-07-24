#include <iostream>
#include <new>
#include <limits>
using namespace std;

int integerInput();
int getSize();
int secondLargest(int, int*);

int main()
{
    int size, ans, *arr;
    cout << "Please enter the size of the array: ";
    size = getSize();
    arr = new (nothrow) int[size];
    if (arr == nullptr)
    {
        cout << "Failed to allocate memory, exiting...";
        exit(0);
    }
    cout << "Please enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        arr[i] = integerInput();
    }

    ans = secondLargest(size, arr);

    cout << endl << "The second largest number in the given array is: " << ans << endl;

    return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
    int size = integerInput();

    if (size <= 0)
    {
        cout << "Invalid size!";
        return 0;
    }

    return size;
}

int secondLargest(int size, int *arr)
{
    int max = 0, secmax = 0, ind = 0;
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i] >= max)
        {
            secmax = max;
            max = arr[i];
        }
        if (secmax <= arr[i] && arr[i] != max)
        {
            secmax = arr[i];
        }
    }

    return secmax;
}