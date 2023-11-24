#include "PmergeMe.hpp"

int main(int ac, char** av) {
  std::cout << "Before : ";
  std::vector<int> init_vec;
  for (int i = 1; i < ac; i++) {
    init_vec.push_back(std::atoi(av[i]));
    std::cout << init_vec[i - 1] << " ";
    if (init_vec[i - 1] <= 0) {
      std::cout << std::endl
                << "Error: Invalid input. Only positive integer." << std::endl;
      std::exit(1);
    }
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

  std::vector<int> result_vec = chainingSortingVector(init_vec);
  printing("After: ", result_vec);

  compareSet(init_set, result_vec);

  std::deque<int> init_deq(init_vec.begin(), init_vec.end());
  std::deque<int> result_deq = chainingSortingDeque(init_deq);

  compareSet(init_set, result_deq);

  calcTime(init_vec, &chainingSortingVector, "vector");
  calcTime(init_deq, &chainingSortingDeque, "deque");

  return 0;
}