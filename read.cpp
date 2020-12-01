#include <bits/stdc++.h>
using namespace std;
string check(string, string);

//reading a key from the file
void read(string file_path)
{

    ifstream file;
    file.open(file_path);

    //getting key input from user

    string key;
    cout << " Enter the key to be searched: " << endl;
    cin >> key;
    //reading through the file
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp))
        { //read data from file object and put it into string.
            string c = check(tp, key);
            if (c != "")
            {
                cout << key << " " << c << " " << endl;
                return;
            }
        }

        cout << " key not available" << endl;
        file.close(); //close the file object.
    }
}