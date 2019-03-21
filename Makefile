all: output

output: HeapSortClient.o MinHeap.o HeapSort.o
	g++ HeapSortClient.o MinHeap.o HeapSort.o -o HeapSortExe

HeapSortClient.o: HeapSortClient.cpp
	g++ -c HeapSortClient.cpp

MinHeap.o: MinHeap.cpp
	g++ -c MinHeap.cpp

HeapSort.o: HeapSort.cpp
	g++ -c HeapSort.cpp

clean: 
	rm *.o HeapSortExe