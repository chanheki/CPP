#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <sys/time.h>

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  PmergeMe(const PmergeMe& src);
  PmergeMe& operator=(PmergeMe const& rhs);

  int _solo;

 public:
  std::vector<int> jacobsthalStorage;
  std::vector<std::pair<int, int> > _before_vec;
  std::vector<int> _result_vec;

  PmergeMe(void);
  PmergeMe(const std::vector<int>& sequenceVector);
  ~PmergeMe(void);

  void chaining(int ac, char** av, PmergeMe& pmerge);
  int getSolo() const;
  void setSolo(int s);

  void vecPushBack(int const& mc, int const& pe);
  void fordJohnsonSort();
  size_t findInSorted(int i);
};
void printingPairVec(const std::string& msg,
                     const std::vector<std::pair<int, int> >& container,
                     int& _solo);

template <typename T>
void printing(const std::string& msg, const T& container) {
  std::cout << msg;
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void calcTime(T& container, void (*fordJohnsonSort)(T&, int, int)) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  fordJohnsonSort(container, 0, container.size() - 1);
  gettimeofday(&end, NULL);

  unsigned long long startTimeMicroSeconds =
      start.tv_sec * 1000000UL + start.tv_usec;
  unsigned long long endTimeMicroSeconds = end.tv_sec * 1000000UL + end.tv_usec;
  unsigned long long timeMicroSeconds =
      (endTimeMicroSeconds - startTimeMicroSeconds);
  std::cout << "Time to process a range of " << container.size()
            << " elements with std::container type " << std::fixed
            << std::setprecision(10) << timeMicroSeconds << " us" << std::endl;
}

int binarySearchInsertPos(const std::vector<std::pair<int, int> >& sorted_vec,
                          const int& target);

size_t _findInSorted(int i, std::vector<int>& sorted_vec);
std::vector<int> chaining(std::vector<int> vec);

#endif
