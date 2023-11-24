#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}

std::vector<int> chainingSortingVector(std::vector<int> vec) {
  std::vector<int> result;
  std::vector<std::pair<int, int> > pair_vec;
  int solo = 0;

  for (size_t i = 1; i < vec.size(); i += 2) {
    if (vec[i] > vec[i - 1]) {
      pair_vec.push_back(std::make_pair(vec[i], vec[i - 1]));
    } else if (vec[i] < vec[i - 1]) {
      pair_vec.push_back(std::make_pair(vec[i - 1], vec[i]));
    }
  }

  if (vec.size() % 2 != 0) {
    solo = vec[vec.size() - 1];
  }

  if (!isSortedAscending(pair_vec)) {
    std::vector<int> temp;
    std::vector<int> sorted_mainchain;
    for (size_t i = 0; i < pair_vec.size(); i++) {
      temp.push_back(pair_vec[i].first);
    }
    sorted_mainchain = chainingSortingVector(temp);
    std::vector<int> sorted_pendingelement;
    for (size_t j = 0; j < sorted_mainchain.size(); j++) {
      for (size_t i = 0; i < pair_vec.size(); i++) {
        if (pair_vec[i].first == sorted_mainchain[j]) {
          sorted_pendingelement.push_back(pair_vec[i].second);
          break;
        }
      }
    }
    pair_vec.clear();
    for (size_t i = 0; i < sorted_mainchain.size(); i++) {
      pair_vec.push_back(
          std::make_pair(sorted_mainchain[i], sorted_pendingelement[i]));
    }
  }

  for (size_t i = 0; i < pair_vec.size(); i++) {
    result.push_back(pair_vec[i].first);
  }

  if (pair_vec.size() < 3) {
    for (size_t i = 0; i < pair_vec.size(); i++) {
      size_t left = 0;
      size_t right = result.size() ? result.size() - 1 : 0;

      int key = pair_vec[i].second;
      while (left < right) {
        size_t mid = (left + right) / 2;
        if (result[mid] > key)
          right = mid;
        else
          left = mid + 1;
      }
      result.insert(result.begin() + left, key);
    }
  }

  for (size_t i = 3; i <= pair_vec.size(); i++) {
    size_t j = jacobsthal(i);
    size_t minIdx = 0;
    i == 3 ? minIdx = 1 : minIdx = jacobsthal(i - 1) + 1;
    size_t maxIdx = 0;
    j < pair_vec.size() ? maxIdx = j : maxIdx = pair_vec.size();
    for (; maxIdx >= minIdx; maxIdx--) {
      size_t left = 0;
      size_t right = findInPair(pair_vec[maxIdx - 1].first, result);
      int key = pair_vec[maxIdx - 1].second;
      while (left < right) {
        size_t mid = (left + right) / 2;
        if (result[mid] > key)
          right = mid;
        else
          left = mid + 1;
      }
      result.insert(result.begin() + left, key);
    }
    if (j >= pair_vec.size()) break;
  }

  if (solo != 0) {
    result.insert(result.begin() + binarySearchInsertPos(result, solo), solo);
  }

  return result;
}

std::deque<int> chainingSortingDeque(std::deque<int> deq) {
  std::deque<int> result;
  std::deque<std::pair<int, int> > pair_deq;
  int solo = 0;

  for (size_t i = 1; i < deq.size(); i += 2) {
    if (deq[i] > deq[i - 1]) {
      pair_deq.push_back(std::make_pair(deq[i], deq[i - 1]));
    } else if (deq[i] < deq[i - 1]) {
      pair_deq.push_back(std::make_pair(deq[i - 1], deq[i]));
    }
  }

  if (deq.size() % 2 != 0) {
    solo = deq[deq.size() - 1];
  }

  if (!isSortedAscending(pair_deq)) {
    std::deque<int> temp;
    std::deque<int> sorted_mainchain;
    for (size_t i = 0; i < pair_deq.size(); i++) {
      temp.push_back(pair_deq[i].first);
    }
    sorted_mainchain = chainingSortingDeque(temp);
    std::deque<int> sorted_pendingelement;
    for (size_t j = 0; j < sorted_mainchain.size(); j++) {
      for (size_t i = 0; i < pair_deq.size(); i++) {
        if (pair_deq[i].first == sorted_mainchain[j]) {
          sorted_pendingelement.push_back(pair_deq[i].second);
          break;
        }
      }
    }
    pair_deq.clear();
    for (size_t i = 0; i < sorted_mainchain.size(); i++) {
      pair_deq.push_back(
          std::make_pair(sorted_mainchain[i], sorted_pendingelement[i]));
    }
  }

  for (size_t i = 0; i < pair_deq.size(); i++) {
    result.push_back(pair_deq[i].first);
  }

  if (pair_deq.size() < 3) {
    for (size_t i = 0; i < pair_deq.size(); i++) {
      size_t left = 0;
      size_t right = result.size() ? result.size() - 1 : 0;
      int key = pair_deq[i].second;
      while (left < right) {
        size_t mid = (left + right) / 2;
        if (result[mid] > key)
          right = mid;
        else
          left = mid + 1;
      }
      result.insert(result.begin() + left, key);
    }
  }

  for (size_t i = 3; i <= pair_deq.size(); i++) {
    size_t j = jacobsthal(i);
    size_t minIdx = 0;
    i == 3 ? minIdx = 1 : minIdx = jacobsthal(i - 1) + 1;
    size_t maxIdx = 0;
    j < pair_deq.size() ? maxIdx = j : maxIdx = pair_deq.size();
    for (; maxIdx >= minIdx; maxIdx--) {
      size_t left = 0;
      size_t right = findInPair(pair_deq[maxIdx - 1].first, result);
      int key = pair_deq[maxIdx - 1].second;
      while (left < right) {
        size_t mid = (left + right) / 2;
        if (result[mid] > key)
          right = mid;
        else
          left = mid + 1;
      }
      result.insert(result.begin() + left, key);
    }
    if (j >= pair_deq.size()) break;
  }

  if (solo != 0) {
    result.insert(result.begin() + binarySearchInsertPos(result, solo), solo);
  }

  return result;
}

int jacobsthal(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...