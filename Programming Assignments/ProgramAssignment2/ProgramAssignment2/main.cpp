#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iomanip>

using namespace std;

//Running times of one single algorithm step
double RT_linearSearch = 0;
double RT_binarySearch = 0;

void quickSort(vector<int> &vec, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = vec[(left + right) / 2];
    
    /* partition */
    while (i <= j)
    {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;
        if (i <= j) {
            tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(vec, left, j);
    if (i < right)
        quickSort(vec, i, right);
}

//Linear Search
int linearSearch(vector<int> vec, int key, int n)
{
    for (int i = 0; i < n; i++)
    {
      
        if (vec[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//Binary Search
int binarySearch(vector<int> vec, int key, int n)
{
    int left = 0;
    int right = n-1;
    
    while (right >= left)
    {
        int mid = (left + right)/2;
        
        if (vec[mid] == key)
        {
            return mid;
        }
        else if (vec[mid] < key)
        {
            left = mid+1;
        }
        else if (vec[mid] > key)
        {
            right = mid-1;
        }
    }
    return -1;
}

void LinearSearchTest(int n)
{
    //Variables for testing running time
    clock_t begin, end;
    double elapsed_secs;
    double key_index;
    
    //Variables for number arrays
    vector <int> a = {};
    int min, max, random, key;
    min = -5000;
    max = 5000;
    srand(time(NULL));
    
    //Test running time for Linear Search algorithm
    cout << "LINEAR SEARCH" << endl;
    
    //Generate n - 1 amount of random numbers from -5000 to 5000 and store them into an integer vector
    for (int i = 0; i < (n-1); i++)
    {
        random = rand()%(max-min)+min;
        a.push_back(random);
    }
    //Last element, n, is 7000 and is the key for this program
    a.push_back(7000);
    key = a[n];
    
    begin = clock();
    
    //Linear Search
    key_index = linearSearch(a, key, n);
    
    end = clock();
    a.clear();
    
    //Running time calculations
    elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
    
    //Print average running time
    cout << "Worst-Case Running Time: " << elapsed_secs << " ms" << endl;
    RT_linearSearch = elapsed_secs/n;
    cout << "Running Time of One Single Algorithm Step: " << RT_linearSearch << " ms" << endl;
    
    cout << endl;
}

void BinarySearchTest(int n)
{
    //Variables for testing running time
    clock_t begin, end;
    double elapsed_secs;
    double key_index;
    
    //Variables for number arrays
    vector <int> a = {};
    int min, max, random, key;
    min = -5000;
    max = 5000;
    srand(time(NULL));
    
    //Test running time for Linear Search algorithm
    cout << "BINARY SEARCH" << endl;
    
    //Generate n - 1 amount of random numbers from -5000 to 5000 and store them into an integer vector
    for (int i = 0; i < (n-1); i++)
    {
        random = rand()%(max-min)+min;
        a.push_back(random);
    }
    //Last element, n, is 7000 and is the key for this program
    a.push_back(7000);
    key = a[n];
    
    //Sort integer vector using Bubble Sort
    quickSort(a, 0, n);
    
    begin = clock();
    
    //Binary Search
    key_index = binarySearch(a, key, n);
    
    end = clock();
    a.clear();
    
    //Running time calculations
    elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
    
    //Print average running time
    cout << "Worst-Case Running Time: " << elapsed_secs << " ms" << endl;
    RT_binarySearch = elapsed_secs/log2(n);
    cout << "Running Time of One Single Algorithm Step: " << RT_binarySearch << " ms" << endl;
    
    cout << endl;
}

int main()
{
    cout << "======================= Input Size: n = 10^5 ========================" << endl;
    cout << endl;
    
    int n = 100000;
    LinearSearchTest(n);
    BinarySearchTest(n);
    int new_n = 1000000;
    
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Predicting Running Time for Input Size n = 10^6" << endl;
    cout << endl;
    cout << "* Linear Search = O(n)" << endl;
    cout << "* Binary Search = O(logn)" << endl;
    cout << "* Avg Running Time = f(n) * (Running Time of One Single Algorithm Step)" << endl;
    cout << endl;
    cout << "Linear Search --> (" << new_n << ") * (" << RT_linearSearch << " ms) = " << (new_n * RT_linearSearch) << " ms" << endl;
    cout << "Binary Search --> (log(" << new_n << ")) * (" << RT_binarySearch << " ms) = " << (log2(new_n) * RT_binarySearch) << " ms" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "======================= Input Size: n = 10^6 ========================" << endl;
    cout << endl;
    
    LinearSearchTest(new_n);
    BinarySearchTest(new_n);
    
    return 0;
}
