#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>

#define DECIMAL 10

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &obj)
	: input(obj.input), pairs(obj.pairs), main_chain(obj.main_chain) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	input = obj.input;
	pairs = obj.pairs;
	main_chain = obj.main_chain;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::load_data(char *argv[])
{
	for (int i = 1; argv[i] != NULL; i++)
	{
		long int input_val = strtol(argv[i], NULL, DECIMAL);
		if (input_val < 1)
		{
			throw std::runtime_error("Non positive input");
		}
		if (std::find(input.begin(), input.end(), input_val) != input.end())
		{
			throw std::runtime_error("Duplicate value");
		}
		input.push_back(input_val);
	}
}

void merge(std::vector<pair> &arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Create temporary arrays
	std::vector<pair> L(n1);
	std::vector<pair> R(n2);

	// Copy data to temporary arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	// Merge the temporary arrays back into arr[left..right]
	int i = 0;	  // Initial index of first subarray
	int j = 0;	  // Initial index of second subarray
	int k = left; // Initial index of merged subarray

	while (i < n1 && j < n2)
	{
		if (L[i].a <= R[j].a)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(std::vector<pair> &arr, int left, int right)
{
	if (left < right)
	{
		// Same as (left+right)/2, but avoids overflow for large left and right
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		// Merge the sorted halves
		merge(arr, left, middle, right);
	}
}

void PmergeMe::swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
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
			this->swap(p.a, p.b);

		pairs.push_back(p);
		it += 2;
	}
	return pairs;
}

std::vector<int> extractFirstFromPairs(std::vector<pair> pairs)
{
	std::vector<int> s;

	std::vector<pair>::iterator it = pairs.begin();
	std::vector<pair>::iterator ite = pairs.end();

	while (it != ite)
	{
		s.push_back(it->a);
		it++;
	}

	return s;
}

void insertSmallest(std::vector<int> &pend, std::vector<int> &main_chain)
{
	std::vector<int>::iterator pos = main_chain.begin();
	main_chain.insert(pos, pend[0]);
}

void PmergeMe::separatePairs(std::vector<pair> pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		main_chain.push_back(pairs[i].a);
		pend.push_back(pairs[i].b);
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

void insertionSort(std::vector<int> &main_chain, std::vector<int> &pend)
{

	size_t pend_size = pend.size();

	for (size_t i = 1; i < pend_size; ++i)
	{
		int curr_val = pend[i];

		// find location where selected should be inserted
		int loc_idx = binarySearch(main_chain, curr_val, 0, i + 1);
		std::vector<int>::iterator pos = main_chain.begin() + loc_idx;
		main_chain.insert(pos, curr_val);
	}
}

void PmergeMe::sort_data(void)
{
	if (input.size() < 2)
		return;

	bool is_stray = input.size() % 2;

	int straggler = -1;
	if (is_stray)
	{
		straggler = input[input.size() - 1];
		input.pop_back();
	}

	this->pairs = PmergeMe::createSortedPairs(this->input);

	mergeSort(this->pairs, 0, this->pairs.size() - 1);
	PmergeMe::separatePairs(this->pairs);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].a << ", " << pairs[i].b << "), ";
	}
	std::cout << std::endl;

	if (is_stray)
		this->pend.push_back(straggler);

	main_chain.insert(main_chain.begin(), pend[0]);
	insertionSort(this->main_chain, this->pend);

	for (size_t i = 0; i < main_chain.size(); i++)
	{
		std::cout << main_chain[i] << " ";
	}
	std::cout << "\n";

	// for (size_t i = 0; i < pend.size(); i++)
	// {
	// 	std::cout << pend[i] << " ";
	// }
	// std::cout << "\n";

	// std::cout << "\n";
}
