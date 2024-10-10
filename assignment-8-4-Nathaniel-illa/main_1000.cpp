#include "main.hpp"

int main()
{
	int N = 1000;
	double totalswapcnt = 0;
	chrono::nanoseconds totalduration = chrono::nanoseconds::zero();
	chrono::nanoseconds duration = chrono::nanoseconds::zero();
	vector<int> numbers, copied;

	srand(time(0));
	// Quick Sort
	for (int i = 0; i < 1000; i++)
	{
		swapcnt = 0;
		numbers.clear();
		fillvector(numbers, N);
		auto start = high_resolution_clock::now();
		quicksort(numbers, 0, 999);
		auto stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		totalswapcnt += swapcnt;
		cout << swapcnt << "\t" << duration.count() << endl;
		totalduration += duration;
	}
	swapcnt = totalswapcnt / 1000.0;
	duration = duration_cast<nanoseconds>(totalduration / 1000.0);

	// print(numbers);
	cout << "The average comparison count " << swapcnt << endl;
	cout << "The elappsed time  " << duration.count() << endl;
}
