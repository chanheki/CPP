#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

PmergeMe::PmergeMe(void) : _solo(0) {}
PmergeMe::~PmergeMe(void) {}

void PmergeMe::setSolo(int s) { _solo = s; }

int PmergeMe::getSolo() const { return (_solo); }

void PmergeMe::vecPushBack(int const& mc, int const& pe) {
  _before_vec.push_back(std::make_pair(mc, pe));
}

void PmergeMe::printingPairVec(
    const std::string& msg,
    const std::vector<std::pair<int, int> >& container) {
  std::cout << msg;
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i].first << "," << container[i].second << " ";
  }
  if (_solo != 0) {
    std::cout << getSolo();
  }
  std::cout << std::endl;
}

int jacobsthal(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int binarySearchInsertPos(const std::vector<std::pair<int, int> >& sorted_vec,
                          const std::pair<int, int>& target, int endIndex) {
  int start = 0;
  int end = endIndex;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (sorted_vec[mid].first == target.first) {
      return mid;
    } else if (sorted_vec[mid].first < target.first) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return start;
}

size_t PmergeMe::findInSorted(int i) {
  size_t ret = 0;
  for (std::vector<int>::iterator iter = _result_vec.begin();
       iter != _result_vec.end(); iter++) {
    if (i == *iter) break;
    ret++;
  }
  return ret;
}

void PmergeMe::fordJohnsonSort() {
  for (std::vector<std::pair<int, int> >::iterator it = _before_vec.begin();
       it != _before_vec.end(); ++it) {
    _result_vec.push_back(it->first);
  }

  printing("result : ", _result_vec);

  for (size_t i = 3; i <= _before_vec.size(); i++) {
    size_t j = jacobsthal(i);
    size_t minIdx = 0;
    i == 3 ? minIdx = 1 : minIdx = jacobsthal(i - 1) + 1;
    size_t maxIdx = 0;
    j < _before_vec.size() ? maxIdx = j : maxIdx = _before_vec.size();
    for (; maxIdx >= minIdx; maxIdx--) {
      size_t left = 0;
      size_t right = findInSorted(_before_vec[maxIdx - 1].first);
      int key = _before_vec[maxIdx - 1].second;
      while (left < right) {
        size_t mid = (left + right) / 2;
        if (_result_vec[mid] > key)
          right = mid;
        else
          left = mid + 1;
      }
      _result_vec.insert(_result_vec.begin() + left, key);
    }
    if (j >= _before_vec.size()) break;
  }

  // if (_solo != 0) {
  //   binarySearchInsertPos
  // }
}