#ifndef SORT_H
#define SORT_H

#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& a)
{
	std::size_t n = a.size();
	for (std::size_t i = 1; i < n; ++i)
	{
		for (std::size_t j = i; j > 0 && a[j] < a[j-1]; --j)
		{
			std::swap(a[j-1], a[j]);
		}
	}
}

template <typename RandomIt, class <RandomIt> Range<RandomIt, RandomIt> >
void insertion_sort2(std::vector<T>& a)
{
	std::size_t n = a.size();
	for (std::size_t i = 1; i < n; ++i)
	{
		for (std::size_t j = i; j > 0 && a[j] < a[j-1]; --j)
		{
			std::swap(a[j-1], a[j]);
		}
	}
}

#endif // SORT_H