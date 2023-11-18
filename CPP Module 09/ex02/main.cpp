#include "PmergeMe.hpp"

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
  if (a.first == b.first) {
    std::cout << "Error: Invalid input. Duplicate integer." << std::endl;
  }
  return a.first < b.first;
}

void sortPairVector(std::vector<std::pair<int, int> >& vec) {
  std::sort(vec.begin(), vec.end(), comp);
}

int main(int ac, char** av) {
  PmergeMe pmerge;
  int index = 1;
  while (index < ac - 1) {
    int mc = std::atoi(av[index]);
    int pe = std::atoi(av[index + 1]);
    if (mc <= 0 || pe <= 0) {
      std::cout << "Error: Invalid input. Positive integers only." << std::endl;
      return (1);
    }
    if (mc > pe)
      pmerge.vecPushBack(mc, pe);
    else if (mc < pe)
      pmerge.vecPushBack(pe, mc);
    else
      std::cout << "Error: Invalid input. Duplicate integer." << std::endl;
    index += 2;
  }

  if (ac % 2 == 0) {
    pmerge.setSolo(std::atoi(av[ac - 1]));
  }
  pmerge.printingPairVec("Before: ", pmerge._before_vec);

  sortPairVector(pmerge._before_vec);
  pmerge.fordJohnsonSort();
  printing("After: ", pmerge._result_vec);
}
