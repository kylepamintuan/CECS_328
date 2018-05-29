#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

double avg_run_time_quickSort = 0;
double avg_run_time_insertion_sort = 0;
double avg_run_time_heap_sort = 0;

//Quick Sort
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
        if (i <= j)
        {
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

//Selection Sort
void selectionSort(vector<int> &vec, int n)
{
    //pos_min is short for position of min
    int pos_min,temp;
    
    for (int i=0; i < n-1; i++)
    {
        pos_min = i;//set pos_min to the current index of array
        
        for (int j=i+1; j < n; j++)
        {
            
            if (vec[j] < vec[pos_min])
                pos_min=j;
            //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }
        
        //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        if (pos_min != i)
        {
            temp = vec[i];
            vec[i] = vec[pos_min];
            vec[pos_min] = temp;
        }
    }
}

// Max Heapify
void maxHeapify(int a[], int i, int n)
{
    int left, right, largest, temp;
    left = i*2;
    right = ((i * 2) + 1);
    
    if ((left <= n) && a[left] > a[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if ((right <= n) && (a[right] > a[largest]))
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxHeapify(a, largest, n);
    }
}

// Build Max Heap
void buildMaxHeap(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        maxHeapify(a, k, n);
    }
}

// Heap Sort
void heapSort(int a[], int n)
{
    buildMaxHeap(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeapify(a, 1, i - 1);
    }
}

// Output function
void printArray(vector<int> &vec, int n)
{
    //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
}

int main()
{
    //User input
    int n;
    cout << "Enter a positive integer" << endl;
    cin >> n;
    
    cout << endl;
    
    //Variables for testing running time
    clock_t begin, end;
    double elapsed_secs;
    double iterations, total_running_time;
    
    //Variables for number arrays
    vector <int> a = {};
    int min, max, random;
    min = -7000;
    max = 7000;
    srand(time(NULL));
    
    cout << "================= QUICK SORT =================" << endl;
    for (int i = 0; i < 1; i++)
    //for (int i = 0; i < 100; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }
        
        cout << endl;
        cout << "Unsorted array: " << endl;
        printArray(a, n);
        
        begin = clock();
        
        //Quick Sort
        quickSort(a, 0, n);
        
        end = clock();
        
        cout << endl;
        cout << "Sorted array: " << endl;
        printArray(a, n);
        
        a.clear();
        
        //Running time calculations
        elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
        iterations++;
        total_running_time += elapsed_secs;
    }
    
    //Print average running time
    avg_run_time_quickSort = total_running_time/iterations;
    cout << "Average Running Time: " << avg_run_time_quickSort << " milliseconds" << endl;
    
    //Reset
    iterations = 0;
    total_running_time = 0;
    
    cout << endl;
    
    cout << "================= SELECTION SORT =================" << endl;
    for (int i = 0; i < 1; i++)
    //for (int i = 0; i < 100; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }
        
        cout << endl;
        cout << "Unsorted array: " << endl;
        printArray(a, n);
        
        begin = clock();
        
        //Insertion Sort
        selectionSort(a, n);
        
        end = clock();
        
        cout << endl;
        cout << "Sorted array: " << endl;
        printArray(a, n);
        
        a.clear();
        
        //Running time calculations
        elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
        iterations++;
        total_running_time += elapsed_secs;
    }
    
    //Print average running time
    avg_run_time_insertion_sort = total_running_time/iterations;
    cout << "Average Running Time: " << avg_run_time_insertion_sort << " milliseconds" << endl;
    cout << endl;
    
    //Reset
    iterations = 0;
    total_running_time = 0;
    
    cout << "================= HEAP SORT =================" << endl;
    for (int i = 0; i < 1; i++)
    //for (int i = 0; i < 100; i++)
    {
        int arr[n];
        
        for (int i = 1; i <= n; i++)
        {
            random = rand()%(max-min)+min;
            arr[i] = random;
        }
        
        cout << endl;
        cout << "Unsorted array: " << endl;
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << endl;
        }
        
        begin = clock();
        
        //Heap Sort
        heapSort(arr, n);
        
        end = clock();
        
        cout << endl;
        cout << "Sorted array: " << endl;
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i] << endl;
        }
        
        //Running time calculations
        elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
        iterations++;
        total_running_time += elapsed_secs;
    }
    
    //Print average running time
    avg_run_time_heap_sort = total_running_time/iterations;
    cout << "Average Running Time: " << avg_run_time_heap_sort << " milliseconds" << endl;
    cout << endl;
    
    return 0;
}
