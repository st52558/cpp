#include "Time.h"
#include <iostream>


void compareArray(IComparable** times, int numberOfTimes) {
	for (int i = 0; i < numberOfTimes - 1; i++) {
		for (int i = 0; i < numberOfTimes - 1; i++)
		{
			if (times[i]->compareTo(times[i + 1]) == 1) {
				IComparable* temp = times[i];
				times[i] = times[i + 1];
				times[i + 1] = temp;
			}
		}
	}
}

void writeAllTimes(IComparable** times, int numberOfTimes) {
	for (int i = 0; i < numberOfTimes; i++)
	{
		cout << times[i]->toString() << endl;
	}
}

int main(int agrc, char** argv)
{
	IComparable** times = new IComparable * [10];

	for (int i = 0; i < 10; i++)
	{
		try
		{
			times[i] = new Time(rand() % 24, rand() % 60, rand() % 60);
		}
		catch (const char* ex)
		{
			cout << ex << endl;
		}
	}
	writeAllTimes(times, 10);
	cout << "--------------" << endl;
	compareArray(times, 10);
	writeAllTimes(times, 10);
	return 0;
}
