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
		if (input_val < 0)
		{
			throw std::runtime_error("Negative value");
		}
		// if (std::find(input.begin(), input.end(), input_val) != input.end())
		// {
		// 	throw std::runtime_error("Dublicate value");
		// }
		input.push_back(input_val);
	}
}

// Merge function to merge two sorted arrays
// void merge(std::vector<pair> arr, std::vector<pair> left, int leftSize, std::vector<pair> right, int rightSize);
void merge(std::vector<pair> &arr, std::vector<pair> &left, std::vector<pair> &right)
{
	int left_size = left.size();
	int right_size = right.size();

	int i = 0, j = 0, k = 0;
	while (i < left_size && j < right_size)
	{
		if (left[i].b <= right[j].b)
		{
			arr[k++] = left[i++];
		}
		else
		{
			arr[k++] = right[j++];
		}
	}
	while (i < left_size)
	{
		arr[k++] = left[i++];
	}
	while (j < right_size)
	{
		arr[k++] = right[j++];
	}
}

// Recursive Merge Sort function to sort the array
void MergeSort(std::vector<pair> &arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);

	std::vector<pair> left_arr(mid - left + 1);
	std::vector<pair> right_arr(right - mid);

	for (int i = 0; i <= mid - left; i++)
	{
		left_arr[i] = arr[left + i];
	}
	for (int i = 0; i < right - mid; i++)
	{
		right_arr[i] = arr[mid + 1 + i];
	}
	// merge(arr, left_arr, mid - left + 1, right_arr, right - mid);
	merge(arr, left_arr, right_arr);
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

		if (p.a > p.b)
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
		main_chain.push_back(pairs[i].b);
		pend.push_back(pairs[i].a);
	}
}

int binarySearch(std::vector<int> arr, int lookup_val, int low, int high)
{
	if (high <= low)
		return (lookup_val > arr[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (lookup_val == arr[mid])
		return mid + 1;

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
		int loc_idx = binarySearch(main_chain, curr_val, 0, i);
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

	MergeSort(this->pairs, 0, this->pairs.size() - 1);
	PmergeMe::separatePairs(this->pairs);
	insertSmallest(this->pend, this->main_chain);

	if (is_stray)
		this->pend.push_back(straggler);

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

	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i] << " ";
	// 	// std::cout << "(" << pairs[i].a << ", " << pairs[i].b << ")\n";
	// }
	// std::cout << "\n";
}
