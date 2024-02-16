cmake_minimum_required(VERSION 3.22)
project(algorithm-template-cpp)

set(CMAKE_CXX_STANDARD 14)


add_executable(dijkstra dijkstra.cpp)
add_executable(heapsort heapsort.cpp)
add_executable(mergesort mergesort.cpp)
add_executable(trie trie.cpp)
add_executable(quicksort quicksort.cpp)
add_executable(bucketsort bucketsort.cpp)