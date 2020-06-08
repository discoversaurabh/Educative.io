/*
Write a function to generate the generalized abbreviations of a word.

Note: The order of the output does not matter.

Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

*/

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

int isNum(char c)
{
  if(c >= '1' && c <= '9')
    return (int)(c-'0');
  else 
    return 0; 
}

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    vector<string> result;
    // TODO: Write your code here
    int len = word.length();
    if(!len) return result;

    result.push_back({});

    for(int i=0; i<word.length(); i++)
    {
      vector<string> newRes;
      for(auto p: result)
      {
        int l = p.length();
        int n = isNum(p[l-1]);

        if(n>0)
        {
          string s = p;
          s[l-1] = ('0' + ++n);
          newRes.push_back(s);
          //chek for 9 ...leave for now
        }
        else
        {
          string s2 = p + '1';
          newRes.push_back(s2);
        }
        string s3 = p + word[i];
        newRes.push_back(s3);
      }
      result = newRes;
    }


    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
