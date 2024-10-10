#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fillvector(vector<int> &, int size);
void quicksort(vector<int> &, int, int);
int partition(vector<int> &, int, int);
void print(const vector<int>&);
void print2(const vector<int>&, int, int);

int swapcnt = 0;

void fillvector(vector<int> &numbers, int N) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < N; i++)
        numbers.push_back(rand() % 1000);
}

int partition(vector<int> &numbers, int first, int last) {
    int pivot = numbers[last]; // Choose the last element as pivot
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swap(numbers[i], numbers[j]);
            swapcnt++; // Increment swap count
        }
    }
    swap(numbers[i + 1], numbers[last]); // Place pivot in correct position
    swapcnt++; // Increment swap count for pivot
    return i + 1; // Return the pivot index
}

void quicksort(vector<int> &numbers, int first, int last) {
    if (first < last) {
        int pidx = partition(numbers, first, last); // Partition the array
        quicksort(numbers, first, pidx - 1); // Sort the left subarray
        quicksort(numbers, pidx + 1, last); // Sort the right subarray
    }
}

void print(const vector<int> &numbers) {
    for (auto v : numbers)
        cout << v << "\t";
    cout << endl;
}

void print2(const vector<int> &numbers, int s, int e) {
    for (int i = s; i <= e; i++)
        cout << numbers[i] << "\t";
    cout << endl;
}