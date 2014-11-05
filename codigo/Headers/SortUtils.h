#include <vector>

class SortUtils
{
public:
	template<class T>
	vector<T> &quickSort(vector<T> &items);
	
	template<class T>
	void quickSort(vector<T> &items, unsigned left, unsigned right);
};

template<class T>
T &SortUtils::quickSort(vector<T> &items)
{
	quickSort(items, 0, items.size() - 1);
}

template<class T>
void SortUtils::quickSort(vector<T> &items, unsigned left, unsigned right)
{
	int i, j, x, y;
	i = left;
	j = right;
	x = items[(left + right) / 2];

	while (i <= j)
	{
		while (items[i] < x && i < right)
		{
			i++;
		}
		while (items[j] > x && j > left)
		{
			j--;
		}
		if (i <= j)
		{
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++;
			j--;
		}
	}
	if (j > left)
	{
		quickSort(items, left, j);
	}
	if (i < right)
	{
		quickSort(items, i, right);
	}
}