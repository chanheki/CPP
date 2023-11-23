#include "PmergeMe.hpp"

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
  if (a.first == b.first) {
    std::cout << "Error: Invalid input. Duplicate integer." << std::endl;
    std::exit(1);
  }
  return a.first < b.first;
}

void sortPairVector(std::vector<std::pair<int, int> >& vec) {
  std::sort(vec.begin(), vec.end(), comp);
}

void compareSetAndVector(const std::set<int>& _set,
                         const std::vector<int>& _vec) {
  // set과 vector의 요소 비교
  std::set<int>::const_iterator set_it = _set.begin();
  for (size_t i = 0; i < _vec.size(); ++i, ++set_it) {
    if (*set_it != _vec[i]) {
      std::cout << "not ordered" << std::endl;
      std::exit(1);
    }
  }
}

int main(int ac, char** av) {
  PmergeMe pmerge;

  std::cout << "Before : ";
  std::vector<int> init_vec;
  for (int i = 1; i < ac; i++) {
    init_vec.push_back(std::atoi(av[i]));
    std::cout << init_vec[i - 1] << " ";
  }
  std::cout << std::endl;

  std::set<int> init_set(init_vec.begin(), init_vec.end());

  if (init_set.size() != init_vec.size()) {
    std::cout << "Error: Invalid input. Duplicate integer." << std::endl;
    std::exit(1);
  }

  if (init_vec.empty()) {
    std::cout << "Error: Invalid input. Need argument " << std::endl;
    std::exit(1);
  }

  std::vector<int> result_vec = chaining(init_vec);
  printing("After: ", result_vec);

  compareSetAndVector(init_set, result_vec);

  // if (ac)
  //   ;
  // if (av[1])
  //   ;
  // std::vector<int> vec;
  // std::cout << vec.size();
  // size_t right = vec.size() ? vec.size() - 1 : 0;
  // std::cout << right;

  // pmerge.chaining(ac, av, pmerge);
  // pmerge.printingPairVec("Before: ", pmerge._before_vec);
  // sortPairVector(pmerge._before_vec);
  // pmerge.fordJohnsonSort();
  // printing("After: ", pmerge._result_vec);
}