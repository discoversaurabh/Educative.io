/*
Target Sum (hard) #
You are given a set of positive numbers and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign. We need to find the total ways to assign symbols to make the sum of the numbers equal to the target ‘S’.

Example 1: #
Input: {1, 1, 2, 3}, S=1
Output: 3
Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}
Example 2: #
Input: {1, 2, 7, 1}, S=9
Output: 2
Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} & {-1+2+7+1}
*/


using namespace std;

#include <iostream>
#include <vector>

class TargetSum {
 public:
  int findTargetSubsets(const vector<int> &num, int S) {
    // TODO: Write your code here 
    int N = num.size();
    if(!N)
    {
      if(!S) return 1;
      else return 0;
    }
    int totalSum = 0;
    for(int n:num)
    {
      totalSum += n;
    }

    S = (totalSum  + S)/2;

    vector<int>DP(S+1, 0);
    DP[0] = 1;
    for(int n=0; n<N; n++)
    {
      for(int s=S; s>=0; s--)
      {
        if(s-num[n] >= 0)
          DP[s] += DP[s-num[n]];
      }
    }

    return DP[S];
  }
};

int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
