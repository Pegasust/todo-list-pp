/*
 * LinkedPriorityList.cpp
 *
 * Authors: Hung Tran, Rick Mercer
 *
 * This class describes one implementation of the abstract base class PriorityList.
 * Like any container, there are insert and remove functions.  Indexes represent
 * priorities and the priorities can change in several ways. The element at
 * index 0 has the highest priority, the element at size()-1 has the lowest priority.
 */
#include <stdexcept>
#include <memory>
#include <string>
#include <QDebug>

template<class Type>
class LinkedPriorityList {

private:
  struct Node {
    Type data;
    std::shared_ptr<Node> next;

    // You may not need this Node constructor
    Node(Type element) {
      data = element;
      next = nullptr;
    }

    Node(Type element, std::shared_ptr<Node> nextRef) {
      data = element;
      next = nextRef;
    }
  };

  std::shared_ptr<Node> first;
  int n;

public:

  // Create an empty list with zero elements
  LinkedPriorityList() {
    first = nullptr;
    n = 0;
  }

  // Return the number of elements currently in this PriorityList
  int size() const  {
    return n;
  }

  // Return true if there are zero elements in this PriorityList
  bool isEmpty() const  {
    return n == 0;
  }

  // If possible, return a reference to the element at the given index. If the
  // index is out of range, throw an invalid_argument exception.
  // When size is 2, the only possible indexes are 0 or 1.
  Type getElementAt(int index) const  {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "\ngetElementAt: index was " + std::to_string(index));
    std::shared_ptr<Node> curr = first;
    for (int j = 0; j < index; j++)
      curr = curr->next;
    return curr->data;
  }

  // If possible, insert the element at the given index.
  // If the index is out of range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void insertElementAt(int index, const Type & el)  {
    if (index < 0 || index > size())
      throw std::invalid_argument(
              "In insertElementAt, index was " + std::to_string(index));

 //   qDebug() << "el: " << el << endl;
    if (index == 0) {
      first = std::shared_ptr<Node>(new Node(el, first));
    } else {
      auto curr = first;
      for (int j = 0; j < index - 1; j++)
        curr = curr->next;
      curr->next = std::shared_ptr<Node>(new Node(el, curr->next));
    }
    n++;
  }

  // If possible, remove the element at the given index.
  // If the index is out of  range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void removeElementAt(int index) {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "In removeElementAt, index was " + std::to_string(index));

    if (index == 0) // special case
      first = first->next;
    else {
      std::shared_ptr<Node> prev = first;
      for (int j = 1; j < index; j++)
        prev = prev->next;
      prev->next = prev->next->next;
    }
    n--;
  }

  // If possible, move the element at index to index + 1.
  // If the index is out of range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void lowerPriorityOf(int index)  {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "In lowerPriorityOf, index was " + std::to_string(index));

    if (index < size() - 1) {
      Type el = getElementAt(index);
      removeElementAt(index);
      insertElementAt(index + 1, el);
    }
  }

  // If possible, move the element at index to index - 1.
  // If the index is out of range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void raisePriorityOf(int index)  {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "In raisePriorityOf, index was " + std::to_string(index));

    if (index > 0) {
      Type el = getElementAt(index);
      removeElementAt(index);
      insertElementAt(index - 1, el);
    }
  }

  // If possible, move the element at the given index to the end of this list.
  // If the index is  out of range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void moveToLast(int index)  {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "In moveToLast, index was " + std::to_string(index));

    Type el = getElementAt(index);
    removeElementAt(index);
    insertElementAt(size(), el);
  }

  // If possible, move the element at the given index to the front of this
  // list. If the index is out of range, throw an invalid_argument exception.
  // When size is 3, the only possible insertion locations are 0, 1, and 2.
  void moveToTop(int index)  {
    if (index >= size() || index < 0)
      throw std::invalid_argument(
              "In moveToTop, index was " + std::to_string(index));

    Type el = getElementAt(index);
    removeElementAt(index);
    insertElementAt(0, el);
  }

};
