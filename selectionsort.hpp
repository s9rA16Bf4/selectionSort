#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include <vector>

template<typename T>
class selectionSort{
private:
  std::vector<T> internalVector; // This will hold our unsorted and hopefully sorted list

public:
  std::vector<T> getVector(); // Returns internalVector
  void sort(); // Sorts our vector
  void loadVector(std::vector<T> &originVector);
};

template<typename T>
std::vector<T> selectionSort<T>::getVector(){ return this->internalVector; }

template<typename T>
void selectionSort<T>::loadVector(std::vector<T> &originVector){ this->internalVector = originVector; }

template<typename T>
void selectionSort<T>::sort(){
  int indexOfMinValue = 0;

  for (unsigned int x = 0; x < this->internalVector.size()-1; x++){
    indexOfMinValue = x;
    for (unsigned int y = x+1; y < this->internalVector.size()-1; y++){
      if (this->internalVector[y] < this->internalVector[x]){ indexOfMinValue = y; }

      // Time to swap
      T temp = this->internalVector[indexOfMinValue];
      this->internalVector[indexOfMinValue] = this->internalVector[x];
      this->internalVector[x] = temp;
    }
  }
}

#endif
