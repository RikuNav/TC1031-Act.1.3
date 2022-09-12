#ifndef SELECTION_H
#define SELECTION_H

#include "header.h"
#include <vector>
#include "ship.h"

// =================================================================
// Performs the selection sort algorithm on a vector.
//
// @param A, a vector of T elements.
// =================================================================

void selectionSort(vector<Ship> &ships) {
	int pos;
	for(int i = ships.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(ships[pos].first_than(ships[j])){ //Cambiar a la comparacion de los barcos first_than
				pos = j;
			}
		}
		if (pos != i){
			swap(ships, i, pos);
		}
	}
}

#endif /* SELECTION_H */
