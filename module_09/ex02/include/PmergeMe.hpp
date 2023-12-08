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
	// static sort(std::deque<int> input);

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
	std::vector<int> input_v;
	std::vector<pair> pairs_v;
	std::vector<int> main_chain_v;
	std::vector<pair> pend_v;
};

#endif
