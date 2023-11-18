#include "MutantStack.hpp"

int main() {
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }
  print("--");
  {
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::list<int> s(mstack);
  }
  print("--");
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();
    print("R-");
    while (it != ite) {
      print(*it);
      ++it;
    }
  }
  print("--");
  {
    MutantStack<int> cmstack;
    cmstack.push(5);
    cmstack.push(17);
    cmstack.push(3);
    cmstack.push(5);
    cmstack.push(737);
    cmstack.push(0);
    MutantStack<int>::const_iterator it = cmstack.cbegin();
    MutantStack<int>::const_iterator ite = cmstack.cend();
    print("C-");
    while (it != ite) {
      print(*it);  // 변경 불가
      ++it;
    }
  }
  print("--");
  {
    MutantStack<int> cmstack;
    cmstack.push(5);
    cmstack.push(17);
    cmstack.push(3);
    cmstack.push(5);
    cmstack.push(737);
    cmstack.push(0);
    MutantStack<int>::const_reverse_iterator it = cmstack.crbegin();
    MutantStack<int>::const_reverse_iterator ite = cmstack.crend();
    print("CR");
    while (it != ite) {
      print(*it);  // 변경 불가
      ++it;
    }
  }

  return 0;
}