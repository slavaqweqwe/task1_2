// CMakeProject2.cpp: определяет точку входа для приложения.
//

#include "task.h"

using namespace std;
void PartSort(vector<int>& v, int part_start, int part_stop, int first_part_2)
{
	int part_size = part_stop - part_start;
	int first_rigt = part_start + first_part_2;
	int first_left = 0;

	vector<int> left_save(first_part_2);

	copy(v.begin() + part_start, v.begin() + first_part_2 + part_start, begin(left_save));

	for (int i = part_start; i <= part_stop; i++)
	{
		if (first_left < first_part_2 && first_rigt <= part_start + part_size)
		{
			if (left_save[first_left] > v[first_rigt])
			{
				v[i] = v[first_rigt];
				first_rigt++;

			}
			else {
				v[i] = left_save[first_left];
				first_left++;
			}
		}
		else {
			if (first_left >= first_part_2)
			{
				v[i] = v[first_rigt];
				first_rigt++;

			}
			else {
				v[i] = left_save[first_left];
				first_left++;
			}
		}
	}
}
void testspace::Sort(vector<int>& v)
{

	int c = v.size();
	int num_step = 0;

	num_step = c / 2 + c % 2;
	for (int j = 1; j <= num_step; j++) {

		for (int i = 0; i < v.size(); i += (1 << j))
		{
			if (i + (1 << j) - 1 < v.size())
				PartSort(v, i, i + (1 << j) - 1, (1 << (j - 1)));
			else
				PartSort(v, i, v.size() - 1, (1 << (j - 1)));
		}

	}

}
