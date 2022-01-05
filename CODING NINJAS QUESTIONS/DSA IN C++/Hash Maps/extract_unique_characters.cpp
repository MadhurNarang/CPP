#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string unique_characters(string s)
{
    string ans;
    unordered_map<char, int> cmap;
    for (int i = 0; i < s.size(); i++)
    {
        if (cmap.count(s[i]) == 0)
        {
            ans += s[i];
            cmap[s[i]] = 1;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << unique_characters(s) << endl;
    return 0;
}
