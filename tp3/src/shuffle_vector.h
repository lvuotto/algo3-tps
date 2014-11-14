#ifndef SHUFFLE_VECTOR_H
#define SHUFFLE_VECTOR_H

#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
template<typename T, typename A>
void shuffle_vector_range_from_end(vector<T, A>& vec, unsigned int limit, unsigned int seed = 0);


template<typename T, typename A>
void shuffle_vector_range_from_end(vector<T, A>& vec, unsigned int limit, unsigned int seed = 0)
{
  if (seed == 0) {
    seed = std::chrono::system_clock::now().time_since_epoch().count();
  }
  std::default_random_engine generator(seed);

  unsigned int index = vec.size() < limit ? 0 : vec.size() - limit;
  shuffle(vec.begin() + index, vec.end(), generator);
}

#endif
