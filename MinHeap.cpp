/*
This file contains the declarations for the functions used to implement 
a min-heap. 
*/

#include "MinHeap.hpp"
#include <iostream>


    MinHeap::MinHeap(int* array, int size) {
    	heapBuild(array, size);
    }




    MinHeap::MinHeap() {
    }




	int MinHeap::parentIndex(int index) {
		return (index - 1)/2;
	}




	int MinHeap::leftChildIndex(int index) {
		return index * 2 + 1;
	}




	int MinHeap::rightChildIndex(int index) {
		return index * 2 + 2;
	}




	void MinHeap::percolateUp(int index) {
		if(index < 0 || index > nodes.size() - 1) {
			return;
		}
		int currentIndex = index;
		while (parentIndex(currentIndex) >= 0 &&
		       nodes[currentIndex] < nodes[parentIndex(currentIndex)]) {
			std::swap(nodes[currentIndex], nodes[parentIndex(currentIndex)]);
			currentIndex = parentIndex(currentIndex);
		}
	}




	void MinHeap::percolateDown(int index) {
		if(index < 0 || index > nodes.size() - 1) {
			return;
		}
		int currentIndex = index;
		int min;

		if(rightChildIndex(currentIndex) < nodes.size()) {
			// If the right child is in range so is the left child since the 
			// heap is a complete tree
			if(nodes[rightChildIndex(currentIndex)] < 
				nodes[leftChildIndex(currentIndex)]) {
				min = rightChildIndex(currentIndex);
			} else {
				min = leftChildIndex(currentIndex);
			}
		} else if (leftChildIndex(currentIndex) < nodes.size()){
			min = leftChildIndex(currentIndex);
		} else {
			// Neither child is in range. 
			return;
		}

		while(min < nodes.size() && nodes[min] < nodes[currentIndex]) {
			std::swap(nodes[min], nodes[currentIndex]);

			currentIndex = min;


			if(rightChildIndex(currentIndex) < nodes.size()) {
			// If the right child is in range so is the left child since the 
			// heap is a complete tree
			if(nodes[rightChildIndex(currentIndex)] < 
				nodes[leftChildIndex(currentIndex)]) {
				min = rightChildIndex(currentIndex);
			} else {
				min = leftChildIndex(currentIndex);
			}
			} else if (leftChildIndex(currentIndex) < nodes.size()){
				min = leftChildIndex(currentIndex);
			} else {
				// Neither child is in range. 
				return;
			}
		}
	}




	void MinHeap::heapBuild(int* array, int size) {
		for(int i = 0; i < size; i ++) {
			nodes.push_back(array[i]);
		}
		for(int i = (size - 2)/2; i >= 0; i --) {
			percolateDown(i);
		}
	}




	void MinHeap::insert(int key) {
		nodes.push_back(key);
		percolateUp(nodes.size() - 1);
	}




	int MinHeap::deleteMin() {
		if(!(nodes.size() > 0)) {
			throw MinHeapException("Deletion is not allowed on empty heap.");
		}
		int min = nodes[0];
		nodes[0] = nodes.back();
		nodes.pop_back();
		percolateDown(0);
		return min; 
	}




	void MinHeap::increaseKey(int index, int amount) {
		if(index < 0 || index > nodes.size()) {
			return;
		}
		nodes[index] += amount;
		percolateDown(index);
	}




	void MinHeap::decreaseKey(int index, int amount) {
		if(index < 0 || index > nodes.size()) {
			return;
		}
		nodes[index] -= amount;
		percolateUp(index);
	}




	void MinHeap::print() {
		for(int i = 0; i < nodes.size(); i ++) {
			std::cout << nodes[i];
			if(i < nodes.size() - 1) { 
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}





