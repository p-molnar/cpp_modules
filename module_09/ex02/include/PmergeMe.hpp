#ifndef PMERGEME__HPP
#define PMERGEME__HPP

#include <vector>

typedef struct
{
	int a;
	int b;
} pair;

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

public:
	void load_data(char *argv[]);
	void sort_data(void);

private:
	void swap(int &a, int &b);
	std::vector<pair> createSortedPairs(std::vector<int> input);

	void separatePairs(std::vector<pair> pairs);

private:
	std::vector<int> input;
	std::vector<pair> pairs;
	std::vector<int> main_chain;
	std::vector<int> pend;
};

#endif
