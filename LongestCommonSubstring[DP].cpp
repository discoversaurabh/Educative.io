/*
LONGEST COMMON SUBSTRING
Given 2 strings of lowercase alphabets A and B of size N and M respectively.

Return the length of longest common substring in A and B.



Input Format

The first argument given is the string A.
The second argument given is the string B.
Output Format

Return the length of longest common substring in A and B.
Constraints

1 <= N, M <= 1000
For Example

Input 1:
    A = "interviewbit"
    B = "intermission"
Output 1:
    5
Explaination 1:
    Longest commen substring in A and B is "inter"

Input 2:
    "interviewbit"
    "interstellarviewbit"
Output 2:
    8

*/

int Solution::solve(string A, string B) {
        int N1 = A.size();
        int N2 = B.size();
        if(!N1 || !N2)  return 0;
        vector<vector<int>> DP(N1+1, vector<int>(N2+1, 0));
        
        int maxN=0;
        
        for(int st1=1; st1<N1+1; st1++)
        {
            for(int st2=1; st2 < N2+1; st2++)
            {
                if(A[st1-1] == B[st2-1])
                {
                    DP[st1][st2] = 1 + DP[st1-1][st2-1];
                    maxN = maxN < DP[st1][st2] ? DP[st1][st2] : maxN;
                }
                else
                {
                    DP[st1][st2] = 0;
                }
            }
        }
        return maxN;
    }
