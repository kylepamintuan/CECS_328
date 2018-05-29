#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

// Linear Search
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

/*
class Parent
{
    public:
        int nodeNumber = 0;
        vector<int> children;
        int visited = 0;
    
};
 */

int main()
{
    // Title
    cout << "========== Bread First Search (BFS) and Depth First Search (DFS) Algorithms ==========" << endl;
    cout << endl;
    
    // Get order and size from the user to make a graph
    int order, size;
    cout << "First, let's make a graph" << endl;
    cout << endl;
    cout << "Input the order |V| (or the # of nodes):" << endl;
    cin >> order;
    cout << "Input the size |E| (or the # of edges): ";
    cout << "*** NOTE: the size must be at most " << order*order-1 << " ***" << endl;
    cin >> size;
    cout << "Creating a random adjacency matrix for graph..." << endl;
    cout << endl;
    
    // Initialize adjacency matrix
    int Adj[order][order];
    
    // Construct the adjacency matrix
    // If user inputs the maximum size...
    if (size == order*order-1)
    {
        // ...fill adjacency matrix with all 1s
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                Adj[i][j] = 1;
            }
        }
        
        // Print adjacency matrix
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                cout <<  Adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        int min, max, random, counter;   // Initialize
        min = 0;                         // Min adjacency matrix index
        max = order*order-1;             // Max adjacency matrix index
        counter = 0;                     // Counts the amount of random numbers chosen
        vector<int> a;                   // Vector to hold random nums. Use this as a tool to produce all unique numbers.
        srand(time(NULL));
        
        // Add first random number to the vector
        random = rand()%(max-min)+min;
        a.push_back(random);
        counter++;
        
        // Now, randomly choose which index of the matrix gets a 1
        while (counter < size)
        {
            random = rand()%(max-min)+min;
            
            // Search for random number in the vector
            int found = linearSearch(a, random, counter);
            
            // If that random number hasn't already been produced, add it to the vector
            if(found == -1)
            {
                a.push_back(random);
                counter++;
            }
        }
        
        /*
        // For debugging...
        quickSort(a, 0, counter-1);
        for (int i=0; i<counter; i++)
        {
            cout << a[i] << endl;
        }
        cout << endl;
        */
        
        // Create ajdanceny matrix
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                // Current index of the matrix
                int index = (i*order)+j;
                
                // For debugging...
                //Adj[i][j] = num;
                
                // Search for current index in the vector
                int found = linearSearch(a, index, counter);
                
                // If found, add a 1. Otherwise, add a 0.
                if (found != -1)
                {
                    Adj[i][j] = 1;
                }
                
                else
                    Adj[i][j] = 0;
            }
        }
        // Print adjacency matrix
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                cout <<  Adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    // Get the starting vertex from the user
    int startingNode;
    cout << "Now, choose a starting vertex 0 to " << order-1 << ":" << endl;
    cin >> startingNode;
    cout << endl;
    
    return 0;
}
