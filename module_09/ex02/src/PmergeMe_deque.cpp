#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>
#include <deque>
#include <algorithm>

void PmergeMe::mergeArr(std::deque<pair> &arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::deque<pair> tmp_left(n1);
	std::deque<pair> tmp_right(n2);

	for (int i = 0; i < n1; i++)
		tmp_left[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		tmp_right[j] = arr[middle + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2)
	{
		if (tmp_left[i].a <= tmp_right[j].a)
		{
			arr[k] = tmp_left[i];
			i++;
		}
		else
		{
			arr[k] = tmp_right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = tmp_left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = tmp_right[j];
		j++;
		k++;
	}
}

void PmergeMe::mergeSort(std::deque<pair> &arr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		mergeArr(arr, left, middle, right);
	}
}

std::deque<pair> PmergeMe::createSortedPairs(std::deque<int> input)
{
	std::deque<int>::iterator it = input.begin();
	std::deque<int>::iterator ite = input.end();

	std::deque<pair> pairs;

	while (it < ite)
	{
		pair p;
		p.a = *it;
		p.b = *(it + 1);

		if (p.a < p.b)
			PmergeMe::swap(p.a, p.b);

		pairs.push_back(p);
		it += 2;
	}
	return pairs;
}

void PmergeMe::separatePairs(std::deque<pair> pairs,
							 std::deque<int> &main_chain,
							 std::deque<pair> &pend)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].a);
		pend.push_back(pairs[i]);
	}
}

int binarySearch(std::deque<int> arr, int lookup_val, int low, int high)
{
	if (high <= low)
		return (lookup_val > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (lookup_val > arr[mid])
		return binarySearch(arr, lookup_val, mid + 1, high);
	return binarySearch(arr, lookup_val, low, mid - 1);
}

void BinarySearchInsert(std::deque<int> &main_chain, std::deque<pair> &pend)
{
	size_t pend_size = pend.size();

	for (size_t i = 1; i < pend_size; i++)
	{
		int curr_val = pend[i].b;
		int search_max = pend[i].a != -1
							 ? std::find(main_chain.begin(), main_chain.end(), pend[i].a) - main_chain.begin()
							 : main_chain.size() - 1;

		int loc_idx = binarySearch(main_chain, curr_val, 0, search_max);

		std::deque<int>::iterator insert_pos = main_chain.begin() + loc_idx;
		main_chain.insert(insert_pos, curr_val);
	}
}

std::deque<int> PmergeMe::sort(std::deque<int> input)
{
	if (input.size() < 2)
		return input;

	bool is_stray = input.size() % 2;

	pair straggler;
	if (is_stray)
	{
		straggler.a = -1;
		straggler.b = input[input.size() - 1];
		input.pop_back();
	}

	std::deque<pair> pairs = createSortedPairs(input);

	PmergeMe::mergeSort(pairs, 0, pairs.size() - 1);

	std::deque<int> main_chain;
	std::deque<pair> pend;
	PmergeMe::separatePairs(pairs, main_chain, pend);

	if (is_stray)
		pend.push_back(straggler);

	main_chain.insert(main_chain.begin(), pend[0].b);
	BinarySearchInsert(main_chain, pend);
	return main_chain;
}
