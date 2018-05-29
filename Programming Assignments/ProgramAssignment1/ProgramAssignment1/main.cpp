#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//Bubble Sort
void bubble_sort (vector<int> &vec, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

//Linear Search
int linearSearch(vector<int> vec, int key, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == key)
            return i;
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
    double key_index, iterations, total_running_time, avg_running_time;
    
    //Variables for number arrays
    vector <int> a = {};
    int min, max, random, key;
    min = -1000;
    max = 1000;
    
    //Test running time for Linear Search algorithm
    cout << "LINEAR SEARCH" << endl;
    for (int i = 0; i < 30; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }

        //Select random number from the integer vector
        key = a[rand()%n];
        
        begin = clock();
        
        //Linear Search
        key_index = linearSearch(a, key, n);
        
        end = clock();
        a.clear();
        
        //Running time calculations
        elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
        iterations++;
        total_running_time += elapsed_secs;
    }
    
    //Print average running time
    avg_running_time = total_running_time/iterations;
    cout << "Average Running Time: " << avg_running_time << " milliseconds" << endl;
    
    //Reset
    key_index = 0;
    iterations = 0;
    total_running_time = 0;
    avg_running_time = 0;
    
    cout << endl;
    
    //Test running time for Linear Search algorithm
    cout << "BINARY SEARCH" << endl;
    for (int i = 0; i < 30; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }
        
        //Sort integer vector using Bubble Sort
        bubble_sort(a, n);
        
        //Select random number from the integer vector
        key = a[rand()%n];
        
        begin = clock();
        
        //Binary Search
        key_index = binarySearch(a, key, n);
        
        end = clock();
        a.clear();
        
        //Running time calculations
        elapsed_secs = double(end - begin) / double(CLOCKS_PER_SEC)*1000;
        iterations++;
        total_running_time += elapsed_secs;
    }
    
    //Print average running time
    avg_running_time = total_running_time/iterations;
    cout << "Average Running Time: " << avg_running_time << " milliseconds" << endl;
    
    cout << endl;
    
    return 0;
}
