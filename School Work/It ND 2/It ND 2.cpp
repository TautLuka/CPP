#include <iostream>
#include <fstream>
using namespace std;

void Determin(int size, int* array, int &max, int &maxDay, int &min, int &minDay, int currentDay);

int main()
{
	int size = 0;
	int daysCount = 0;
	int *array;
	int *modifiedArray;
	int currentDay = 1;
	int maxDay = 0, max = INT_MIN;
	int minDay = 0, min = INT_MAX;

	ifstream Input("data.txt");
	ofstream Output("res.txt");

	Input >> size;
	Input >> daysCount;

	array = new int[size];
	modifiedArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		Input >> array[i];
	}

	while (currentDay < daysCount)
	{
		Determin(size, array, max, maxDay, min, minDay, currentDay);

		currentDay++;

		for (int i = 0; i < size; i++)
		{
			if (i != 0 && i != size-1)
			{
				if (array[i - 1] == 1 && array[i + 1] == 1)
				{
					modifiedArray[i] = 0;
				}
				else if ((array[i - 1] == 1 && array[i + 1] == 0) || (array[i - 1] == 0 && array[i + 1] == 1))
				{
					modifiedArray[i] = 1;
				}
				else
				{
					modifiedArray[i] = (currentDay % 2 == 0) ? 1 : 0;
				}
			}
			else
			{
				modifiedArray[i] = (currentDay % 2 == 0) ? 1 : 0;
			}
		}

		for (int i = 0; i < size; i++)
		{
			array[i] = modifiedArray[i];
		}
	}

	Determin(size, array, max, maxDay, min, minDay, currentDay);

	for (int i = 0; i < size; i++)
	{
		Output << array[i] << " ";
	}

	Output << endl;
	Output << "Night, when the most lanterns glowed : " << maxDay << endl;
	Output << "Night, when the lest lanterns glowed : " << minDay << endl;

}

void Determin(int size, int *array, int &max, int &maxDay, int &min, int &minDay, int currentDay)
{
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == 1)
			temp++;
	}

	if (temp > max)
	{
		max = temp;
		maxDay = currentDay;
	}

	if (temp < min)
	{
		min = temp;
		minDay = currentDay;
	}

	temp = 0;
}