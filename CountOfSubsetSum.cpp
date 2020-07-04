/*

Count of Subset Sum (hard) #
Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our input.
Example 2: #
Input: {1, 2, 7, 1, 5}, S=9
Output: 3
The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}

*/


using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  static int countSubsets(const vector<int> &num, int sum) {
    //TODO: Write - Your - Code
    int N=num.size();
    if(!N)
    {
      if(!sum) return 1;
      else return 0;
    }

    vector<int> DP(sum+1, 0);
    DP[0] = 1;

    for(int n=0; n<N; n++)
    {
      for(int s=sum; s>=0; s--)
      {
        if(s >= num[n])
        {
          DP[s] = DP[s] + DP[s-num[n]];
        }
      }
    }
    return DP[sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}
