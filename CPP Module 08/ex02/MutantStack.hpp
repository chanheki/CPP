#pragma once

#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() : std::stack<T>() {}

  virtual ~MutantStack() {}

  MutantStack(MutantStack const &src) : std::stack<T>(src){};

  MutantStack &operator=(MutantStack const &src) {
    if (this != &src) {
      std::stack<T>::operator=(src);
    }
    return *this;
  }

  // Iterators:
  typedef typename MutantStack<T>::stack::container_type::iterator iterator;
  iterator begin(void) { return this->c.begin(); }
  iterator end(void) { return this->c.end(); }

  typedef typename MutantStack<T>::stack::container_type::reverse_iterator
      reverse_iterator;
  reverse_iterator rbegin(void) { return this->c.rbegin(); }
  reverse_iterator rend(void) { return this->c.rend(); }

  typedef typename MutantStack<T>::stack::container_type::const_iterator
      const_iterator;
  const_iterator cbegin(void) { return this->c.cbegin(); }
  const_iterator cend(void) { return this->c.cend(); }

  typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator
      const_reverse_iterator;
  const_reverse_iterator crbegin(void) { return this->c.crbegin(); }
  const_reverse_iterator crend(void) { return this->c.crend(); }
};

template <typename T>
void print(T const &t) {
  std::cout << t << std::endl;
}

/*
    stack synopsis

namespace std
{

template <class T, class Container = deque<T>>
class stack
{
public:
    typedef Container                                container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;

protected:
    container_type c;

public:
    stack() = default;
    ~stack() = default;

    stack(const stack& q) = default;
    stack(stack&& q) = default;

    stack& operator=(const stack& q) = default;
    stack& operator=(stack&& q) = default;

    explicit stack(const container_type& c);
    explicit stack(container_type&& c);
    template <class Alloc> explicit stack(const Alloc& a);
    template <class Alloc> stack(const container_type& c, const Alloc& a);
    template <class Alloc> stack(container_type&& c, const Alloc& a);
    template <class Alloc> stack(const stack& c, const Alloc& a);
    template <class Alloc> stack(stack&& c, const Alloc& a);

    bool empty() const;
    size_type size() const;
    reference top();
    const_reference top() const;

    void push(const value_type& x);
    void push(value_type&& x);

    void swap(stack& c) noexcept(is_nothrow_swappable_v<Container>)
};


template <class T, class Container>
  bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);
template <class T, class Container>
  bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);

template <class T, class Container>
  void swap(stack<T, Container>& x, stack<T, Container>& y)
  noexcept(noexcept(x.swap(y)));

}  // std

*/
