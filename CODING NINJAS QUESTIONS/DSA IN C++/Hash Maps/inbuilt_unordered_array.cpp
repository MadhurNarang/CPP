#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, int> mymap;

    //insert
    pair<string, int> p("abc", 1);
    mymap.insert(p);
    mymap["def"] = 2;

    //find or access
    cout << mymap["abc"] << endl;
    cout << mymap.at("abc") << endl;
    if (mymap.count("def") > 0)
    {
        cout << mymap["def"] << endl;
    }

    //check presence
    if (mymap.count("ghi") > 0)
    {
        cout << "GHI IS PRESENT" << endl;
    }
    else
    {
        cout << "GHI IS NOT PRESENT" << endl;
    }

    //size
    cout << "SIZE :" << mymap.size() << endl;

    //erase
    mymap.erase("ghi");
    mymap.erase("z");
}
