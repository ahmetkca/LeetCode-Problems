#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        map<char, int> keyboard = {
            {'q', 1},
            {'w', 1},
            {'e', 1},
            {'r', 1},
            {'t', 1},
            {'y', 1},
            {'u', 1},
            {'i', 1},
            {'o', 1},
            {'p', 1},
            {'a', 2},
            {'s', 2},
            {'d', 2},
            {'f', 2},
            {'g', 2},
            {'h', 2},
            {'j', 2},
            {'k', 2},
            {'l', 2},
            {'z', 3},
            {'x', 3},
            {'c', 3},
            {'v', 3},
            {'b', 3},
            {'n', 3},
            {'m', 3},
        };
        vector<string> result;
        for (auto word : words)
        {
            bool isValid = true;
            int row = -1;
            string temp{word};

            // word to lowercase
            transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c)
                      { return ::tolower(c); });
            for (auto ch : temp)
            {
                if (row == -1)
                {
                    row = keyboard[ch];
                }
                else
                {
                    if (row != keyboard[ch])
                    {
                        isValid = false;
                        break;
                    }
                }
            }
            if (isValid)
            {
                result.push_back(word);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};

    vector<string> result = s.findWords(words);
    for (auto word : result)
    {
        cout << word << endl;
    }
    return 0;
}
