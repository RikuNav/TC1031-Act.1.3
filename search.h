// =================================================================
// Performs a sequential search for an element within a vector.
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include "ship.h"
#include <vector>

template <class T>
int sequentialSearch(const std::vector<T> &v, T key) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			return i;
		}
	}
	return -1;
}

#endif /* SEARCH_H */