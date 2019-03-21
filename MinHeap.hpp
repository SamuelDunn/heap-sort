/*
This file contains the class definition for the min-heap used to 
implement the heap-sort algorithm. 
*/

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <vector>
#include <string>


class MinHeap {
private: 
	std::vector<int> nodes;
	void heapBuild(int* array, int size);
public: 
	MinHeap(int* array, int size);
	MinHeap();

	int parentIndex(int index);
	int leftChildIndex(int index);
	int rightChildIndex(int index);
	
	void insert(int key);
	int deleteMin();
	void percolateUp(int index);
	void percolateDown(int index);
	void increaseKey(int index, int amount);
	void decreaseKey(int index, int amount);

	void print();

	class MinHeapException{
	private: 
		std::string message;
	public:
		MinHeapException(std::string message) {
			this->message = message; 
		}
		std::string getMessage() {
			return this->message;
		}
	};
};

#endif /* min-heap_hpp */
