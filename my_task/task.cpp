// CMakeProject2.cpp: определяет точку входа для приложения.
//

#include "task.h"

namespace {
	void PartSort(std::vector<int>& v, size_t part_start, size_t part_stop, size_t first_part_2)
	{
		size_t part_size = part_stop - part_start;
		size_t first_rigt = part_start + first_part_2;
		size_t first_left = 0;
		if (first_rigt <= part_stop)
		{
			std::vector<int> left_save(first_part_2);

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
	}
}

void testspace::Sort(std::vector<int>& v)
{

	size_t vectorSize= v.size();
	int num_step = vectorSize / 2 + vectorSize % 2;
	for (int j = 1; j <= num_step; j++) {

		for (int i = 0; i < vectorSize; i += (1 << j))
		{
			if (i + (1 << j) - 1 < vectorSize)
				PartSort(v, i, i + (1 << j) - 1, (1 << (j - 1)));
			else
				PartSort(v, i, vectorSize - 1, (1 << (j - 1)));
		}

	}

}
