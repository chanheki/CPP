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

void printingPairVec(const std::string& msg,
                     const std::vector<std::pair<int, int> >& container,
                     int& _solo) {
  std::cout << msg;
  for (size_t i = 0; i < container.size(); i++) {
    std::cout << container[i].first << "," << container[i].second << " ";
  }
  if (_solo != 0) {
    std::cout << _solo;
  }
  std::cout << " size : " << container.size() << std::endl;
  std::cout << std::endl;
}

int jacobsthal(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

int binarySearchInsertPos(std::vector<int>& sorted_vec, const int& target) {
  int start = 0;
  int end = sorted_vec.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (sorted_vec[mid] == target) {
      return mid;
    } else if (sorted_vec[mid] < target) {
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

size_t _findInSorted(int i, std::vector<int>& sorted_vec) {
  size_t ret = 0;
  for (std::vector<int>::iterator iter = sorted_vec.begin();
       iter != sorted_vec.end(); iter++) {
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

  if (_solo != 0) {
    _result_vec.insert(
        _result_vec.begin() + binarySearchInsertPos(_result_vec, _solo), _solo);
  }
}

void PmergeMe::chaining(int ac, char** av, PmergeMe& pmerge) {
  int index = 1;

  while (index < ac - 1) {
    int mainChain = std::atoi(av[index]);
    int pendingElement = std::atoi(av[index + 1]);
    if (mainChain <= 0 || pendingElement <= 0) {
      std::cout << "Error: Invalid input. Positive integers only." << std::endl;
      std::exit(1);
    }
    if (mainChain > pendingElement)
      pmerge.vecPushBack(mainChain, pendingElement);
    else if (mainChain < pendingElement)
      pmerge.vecPushBack(pendingElement, mainChain);
    else {
      std::cout << "Error: Invalid input. Duplicate integer. chain"
                << std::endl;
      std::exit(1);
    }

    index += 2;
  }

  if (ac % 2 == 0) {
    pmerge.setSolo(std::atoi(av[ac - 1]));
  }
}

bool isSortedAscending(const std::vector<std::pair<int, int> >& pair_vec) {
  if (pair_vec.size() == 1) return true;  // 원소가 하나면 정렬된 것으로 간주

  for (size_t i = 1; i < pair_vec.size(); ++i) {
    if (pair_vec[i].first < pair_vec[i - 1].first) {
      return false;  // 오름차순이 아님
    }
  }
  return true;
}

std::vector<int> chaining(std::vector<int> vec) {
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
    std::cout << "solo : " << solo << std::endl;
  }

  printingPairVec("pair_vec : ", pair_vec, solo);

  if (!isSortedAscending(pair_vec)) {
    std::vector<int> temp;
    std::vector<int> sorted_mainchain;
    for (size_t i = 0; i < pair_vec.size(); i++) {
      temp.push_back(pair_vec[i].first);
      std::cout << pair_vec[i].first << " " << pair_vec[i].second << std::endl;
    }
    std::cout << "temp : ";
    for (size_t i = 0; i < temp.size(); i++) {
      std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
    sorted_mainchain = chaining(temp);

    std::cout << "sorted_mainchain" << std::endl;
    for (size_t i = 0; i < sorted_mainchain.size(); i++) {
      std::cout << sorted_mainchain[i] << " ";
    }
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

    std::cout << std::endl << "pair_vec" << std::endl;
    for (size_t i = 0; i < pair_vec.size(); i++) {
      std::cout << pair_vec[i].first << " " << pair_vec[i].second << std::endl;
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
      size_t right = _findInSorted(pair_vec[maxIdx - 1].first, result);
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