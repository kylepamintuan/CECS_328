#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

double avg_run_time_quickSort = 0;
double avg_run_time_insertion_sort = 0;

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

//Insertion Sort
void insertion_sort(vector<int> &vec, int length)
{
    int i, j ,tmp;
    
    for (i = 1; i < length; i++)
    {
        j = i;
        
        while (j > 0 && vec[j - 1] > vec[j])
        {
            tmp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = tmp;
            j--;
        }
    }
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
    
    cout << "QUICK SORT" << endl;
    for (int i = 0; i < 100; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }
        
        begin = clock();
        
        //Quick Sort
        quickSort(a, 0, n);
        
        end = clock();
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
    
    cout << "INSERTION SORT" << endl;
    for (int i = 0; i < 100; i++)
    {
        //Generate n amount of random numbers from -100 to 100 and store them into an integer vector
        for (int i = 0; i < n; i++)
        {
            random = rand()%(max-min)+min;
            a.push_back(random);
        }
        
        begin = clock();
        
        //Insertion Sort
        insertion_sort(a, n);
        
        end = clock();
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
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << "Step 7: Now calculate how many instructions your machine can run in one second using the avg running" << endl;
    cout << "        time & growth of Insertion Sort." << endl;
    cout << endl;
    cout << "*** Average Running Time = f(n) * (Running time of one single algorithm step) ***" << endl;
    cout << endl;
    cout << "First, find the running time of one single algorithm step. Call it x." << endl;
    cout << avg_run_time_insertion_sort << " ms = (n^2) * (x)" << endl;
    cout << avg_run_time_insertion_sort << " ms = (" << (n*n) << ") * (x)" << endl;
    
    //Solving for One Single Algorithm Step
    double x = avg_run_time_insertion_sort / (n*n);
    
    cout << "x = " << x << " ms" << endl;
    cout << endl;
    cout << "Now, find f(n) for when running time is equal to 1 second" << endl;
    cout << "f(n) = 1 s / " << (x/1000) << " s" << endl;
    
    //Solving for f(n) instructions
    double func_of_n = 1/(x/1000);
    
    cout << "f(n) = " << func_of_n << " instructions" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    
    return 0;
}
