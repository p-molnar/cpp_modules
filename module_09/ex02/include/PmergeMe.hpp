#ifndef PMERGEME__HPP
#define PMERGEME__HPP

#include <vector>
#include <deque>

typedef struct
{
	int a;
	int b;
} pair;

class PmergeMe
{
private:
	PmergeMe(void);
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

public:
	static std::vector<int> sort(std::vector<int> input);
	static std::deque<int> sort(std::deque<int> input);

private:
	static void swap(int &a, int &b);
	static std::vector<pair> createSortedPairs(std::vector<int> input);
	static void separatePairs(std::vector<pair> pairs,
							  std::vector<int> &main_chain,
							  std::vector<pair> &pend);

	static void separatePairs(std::vector<pair> pairs);
	static void mergeSort(std::vector<pair> &arr, int left, int right);
	static void mergeArr(std::vector<pair> &arr, int left, int middle, int right);

private:
	static std::deque<pair> createSortedPairs(std::deque<int> input);
	static void separatePairs(std::deque<pair> pairs,
							  std::deque<int> &main_chain,
							  std::deque<pair> &pend);

	static void separatePairs(std::deque<pair> pairs);
	static void mergeSort(std::deque<pair> &arr, int left, int right);
	static void mergeArr(std::deque<pair> &arr, int left, int middle, int right);
};

#endif
