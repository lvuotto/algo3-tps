#ifndef SHUFFLE_VECTOR_H
#define SHUFFLE_VECTOR_H

#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
template<typename T, typename A>
void shuffle_vector_range_from_end(vector<T, A>& vec, unsigned int limit, std::default_random_engine generator);


template<typename T, typename A>
void shuffle_vector_range_from_end(vector<T, A>& vec, unsigned int limit, std::default_random_engine generator)
{

  unsigned int index = vec.size() < limit ? 0 : vec.size() - limit;
  shuffle(vec.begin() + index, vec.end(), generator);
}

#endif
