#pragma once
#include "sort_algorithm.h"
#include "intro_sort.h"

class InsertionSort : public SortAlgorithm {
   public:
    void sort(std::vector<int> &data) override;
<<<<<<< HEAD

   private:
    void sort(std::vector<int> &data, int beg, int end);
    friend class IntroSort;
    friend class TimSort;
=======
    friend class IntroSort;
private:
    void sort(std::vector<int> &data, int beg, int end);
>>>>>>> aed072c41b20593989002e1fc509d7eb6fdf6073
};