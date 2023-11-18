#include <vector>

#include "easyfind.hpp"

int main(void) {
  std::vector<int> v;
  v.push_back(7);
  v.push_back(17);
  v.push_back(27);
  v.push_back(37);
  v.push_back(47);
  v.push_back(5);

  print(v[0]);
  print(easyfind(v, 5)[0]);
  print(*(easyfind(v, 7) + 4));

  try {
    easyfind(v, 77);
  } catch (const std::exception& e) {
    print(e.what());
  }

  return 0;
}