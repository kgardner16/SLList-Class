#include "SLList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

int main()
{
  ds::SLList<int> L; //creates a SLList called L

  // randomly add SIZE ints to the array nums, and the SLList L 
  int nums[SIZE];
  srand(time(0)); // setting the seed for rand()

  //fill nums array from back to front, and insert same num to L
  for (int i = SIZE - 1; i >= 0; i--) {
    nums[i] = rand() % 20 + 1; // generating random numbers by rand()
    L.addFirst(nums[i]);
  }

   L.Display();

  //test get(): 
  if (L.get(0) != nums[0])
  {
      cout <<"failed get(0)\n";
  } 
  if (L.get(SIZE - 1) != nums[SIZE - 1])
  {
      cout <<"failed get(last)\n";
  }
  else
  {
      cout << "L.get worked as expected. L.get(0) = " << L.get(0) << " and L.get(last) = " << L.get(SIZE-1) << endl;
  }

  //test copy constructor 
  ds::SLList<int> *K = new ds::SLList<int>(L); //creates a copy of SLList L and calls the new list K

  if (L.size() != K->size() || 
     K->get(0) != nums[0] || 
     K->get(SIZE - 1) != nums[SIZE - 1])
  {
      cout <<"failed copy constructor test\n";
  }
  else
  {
  	  cout <<"passed copy constructor test\n";
  }

   K->Display();


  delete K; // this should not also delete L


  //test removeFirst function
   cout << "RemoveFirst test: ";
   L.removeFirst();
   L.Display();



 
}
