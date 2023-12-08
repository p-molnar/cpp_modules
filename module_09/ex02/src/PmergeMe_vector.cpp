#include "PmergeMe.hpp"

#include <stdexcept>
#include <iostream>
#include <vector>

void PmergeMe::mergeArr(std::vector<pair> &arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	std::vector<pair> tmp_left(n1);
	std::vector<pair> tmp_right(n2);

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

void PmergeMe::mergeSort(std::vector<pair> &arr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		mergeArr(arr, left, middle, right);
	}
}

std::vector<pair> PmergeMe::createSortedPairs(std::vector<int> input)
{
	std::vector<int>::iterator it = input.begin();
	std::vector<int>::iterator ite = input.end();

	std::vector<pair> pairs;

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

void PmergeMe::separatePairs(std::vector<pair> pairs,
							 std::vector<int> &main_chain,
							 std::vector<pair> &pend)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].a);
		pend.push_back(pairs[i]);
	}
}

int binarySearch(std::vector<int> arr, int lookup_val, int low, int high)
{
	if (high <= low)
		return (lookup_val > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (lookup_val > arr[mid])
		return binarySearch(arr, lookup_val, mid + 1, high);
	return binarySearch(arr, lookup_val, low, mid - 1);
}

void BinarySearchInsert(std::vector<int> &main_chain, std::vector<pair> &pend)
{
	size_t pend_size = pend.size();

	for (size_t i = 1; i < pend_size; i++)
	{
		int curr_val = pend[i].b;
		int search_max = pend[i].a != -1
							 ? std::find(main_chain.begin(), main_chain.end(), pend[i].a) - main_chain.begin()
							 : main_chain.size() - 1;

		int loc_idx = binarySearch(main_chain, curr_val, 0, search_max);

		std::vector<int>::iterator insert_pos = main_chain.begin() + loc_idx;
		main_chain.insert(insert_pos, curr_val);
	}
}

std::vector<int> PmergeMe::sort(std::vector<int> input)
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

	std::vector<pair> pairs = createSortedPairs(input);

	PmergeMe::mergeSort(pairs, 0, pairs.size() - 1);

	std::vector<int> main_chain;
	std::vector<pair> pend;
	PmergeMe::separatePairs(pairs, main_chain, pend);

	if (is_stray)
		pend.push_back(straggler);

	main_chain.insert(main_chain.begin(), pend[0].b);
	BinarySearchInsert(main_chain, pend);
	return main_chain;
}
