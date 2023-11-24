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

 public:
  PmergeMe(void);
  ~PmergeMe(void);
};

std::vector<int> chainingSortingVector(std::vector<int> container);
std::deque<int> chainingSortingDeque(std::deque<int> deq);

int jacobsthal(int n);

template <typename T>
void printing(const std::string& msg, const T& container) {
  std::cout << msg;
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void calcTime(T& container, T (*chainingSorting)(T), const std::string& type) {
  struct timeval start, end;
  gettimeofday(&start, NULL);
  chainingSorting(container);
  gettimeofday(&end, NULL);

  unsigned long long startTimeMicroSeconds =
      start.tv_sec * 1000000UL + start.tv_usec;
  unsigned long long endTimeMicroSeconds = end.tv_sec * 1000000UL + end.tv_usec;
  unsigned long long timeMicroSeconds =
      (endTimeMicroSeconds - startTimeMicroSeconds);
  std::cout << "Time to process a range of " << std::fixed
            << std::setprecision(10) << container.size()
            << " elements with std::" << type << " : " << std::fixed
            << std::setprecision(10) << timeMicroSeconds << " us" << std::endl;
}

template <typename T>
size_t findInPair(int i, T& container) {
  size_t ret = 0;

  for (typename T::iterator iter = container.begin(); iter != container.end();
       iter++) {
    if (i == *iter) break;
    ret++;
  }
  return ret;
}

template <typename T>
size_t binarySearchInsertPos(T& sortedContainer, int& target) {
  if (sortedContainer.empty()) return 0;

  size_t start = 0;
  size_t end = sortedContainer.size() - 1;

  while (start <= end) {
    size_t mid = start + (end - start) / 2;

    if (sortedContainer[mid] == target) {
      return mid;
    } else if (sortedContainer[mid] < target) {
      start = mid + 1;
    } else {
      if (mid == 0) break;
      end = mid - 1;
    }
  }
  return start;
}

template <typename T>
bool isSortedAscending(const T& pairContainer) {
  if (pairContainer.empty()) return true;
  if (pairContainer.size() == 1) return true;

  typename T::const_iterator it1 = pairContainer.begin();
  typename T::const_iterator it2 = pairContainer.begin();
  ++it2;

  while (it2 != pairContainer.end()) {
    if (it1->first > it2->first) {
      return false;
    }
    ++it1;
    ++it2;
  }
  return true;
}

template <typename T>
void compareSet(const std::set<int>& _set, const T& container) {
  std::set<int>::const_iterator set_it = _set.begin();
  for (size_t i = 0; i < container.size(); ++i, ++set_it) {
    if (*set_it != container[i]) {
      std::cout << "not ordered" << std::endl;
      std::exit(1);
    }
  }
  // std::cout << "Sort Success" << std::endl;
}

#endif