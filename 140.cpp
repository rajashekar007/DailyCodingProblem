/*
* Question:
* Given an array of integers in which two elements appear exactly once and all 
* other elements appear exactly twice, find the two elements that appear only
* once.
*
* For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. 
* The order does not matter
*/

/* 
* Solution
* Doing Xor of all elements give xor of two unique elements which contains
* the information about the complementary bit position 'x', and that help
* us in classifying two elements into two groups which have the bit set 
* at 'x' and which don't have. After xoring with two element types we are
* left with two elements since each group contains all elements repeated 
* twice except one which is our required number.
* Time Complexity : O(N)
* Space Complexity : O(1)
*/

/*
* How does this problem help in real world?
*
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> give_2_unique(vector<int> ar)
{
  int x = 0;
  for(int i=0;i<ar.size();i++)
    x^=ar[i];
  int num1 = 0, num2 = 0, pos = 1;
  while(!(x&pos))pos<<=1;
  for(int i=0;i<ar.size();i++)
  if(ar[i]&pos)num1^=ar[i];
  else num2^=ar[i];
  return {num1,num2};
}

int main()
{
  vector<int> ar={2, 4, 6, 8, 10, 2, 6, 10, 4, 4, 4, 5};
  vector<int> ans = give_2_unique(ar);
  cout<<ans[0]<<", "<<ans[1]<<endl;
  return 0;
}