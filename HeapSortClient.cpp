/*
 This client program tests the heapSort() function with a variety
 different input arrays and will compare the time-cost of using the heap-sort
 algorithm in each of these different situations.
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "HeapSort.hpp"
using namespace std;

// Size of test arrays
const int ARRAY_SIZE = 10000;
// The values for the test array elements will be chosen from 
// the range [0, NUMBER_RANGE]
const int NUMBER_RANGE = 50000;

int main() {

   srand(static_cast<unsigned>(time(0)));
   long startClock, stopClock;
   int randomArray[ARRAY_SIZE];
   int reverseOrderedArray[ARRAY_SIZE];
   int orderedArray[ARRAY_SIZE];
   int uniformArray[ARRAY_SIZE];
   int nearlyOrderedArray[ARRAY_SIZE];
   int orderedWithDuplicateElements[ARRAY_SIZE];


   for(int count = 0; count < ARRAY_SIZE; count ++) {
      randomArray[count] = rand() % (NUMBER_RANGE + 1);
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      reverseOrderedArray[count] = (ARRAY_SIZE - 1) - count;
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      orderedArray[count] = count;
   }
   int element = rand() % (NUMBER_RANGE + 1);
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      uniformArray[count] = element;
   }
   for(int count = 0; count < ARRAY_SIZE; count ++) {
      if( count % 6 == 0)
         nearlyOrderedArray[count] = rand() % (NUMBER_RANGE + 1);
      else
         nearlyOrderedArray[count] = count;
   }
   for(int count = 0, count2 = 0; count < ARRAY_SIZE; count ++) {
      if(count % 6 == 0)
         count2 ++;
      orderedWithDuplicateElements[count] = count2;
   }


   cout <<  "Time-cost of using heap-sort:"
   << endl << endl;
   cout << fixed << setprecision(4);

   startClock = clock();
   heapSort(orderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array that was sorted smallest to largest." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(orderedArray[count] > orderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   heapSort(randomArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array with randomly chosen elements." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(randomArray[count] > randomArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   heapSort(reverseOrderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array that was sorted largest to smallest." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(reverseOrderedArray[count] > reverseOrderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   heapSort(uniformArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array where all elements are equal." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(uniformArray[count] > uniformArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   heapSort(nearlyOrderedArray, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array with partially sorted elements." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(nearlyOrderedArray[count] > nearlyOrderedArray[count + 1])
         cout << "ERROR" << endl;
   }

   startClock = clock();
   heapSort(orderedWithDuplicateElements, ARRAY_SIZE);
   stopClock = clock();
   cout << "It took "
   << 1000 * static_cast<double>(stopClock - startClock)/CLOCKS_PER_SEC
   << " milliseconds to sort a " << ARRAY_SIZE 
   << " element array with sequences of identical elements." << endl;
   for(int count = 0; count < ARRAY_SIZE - 1; count ++) {
      if(orderedWithDuplicateElements[count] > orderedWithDuplicateElements[count + 1])
         cout << "ERROR" << endl;
   }
   cout << endl;


   return 0;
}





