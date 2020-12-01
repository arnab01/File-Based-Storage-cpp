#include <bits/stdc++.h>
using namespace std;

bool input_check(const string &, string *);

//inserting into a file
void insert(string file_path)
{
    // TODO: Add default
    //opening the file
    ofstream file;
    file.open(file_path, ios_base::app);

    if (!file)
    { // file couldn't be opened error
        cout << "Error: file could not be opened" << endl;
        return;
    }

    else
    {

        //getting key-value content from the user
        string s;

        cout << "Enter content : ";
        cin.ignore();
        getline(cin, s);

        // input size cap validation
        string err_message;
        if (!input_check(s, &err_message))
        {
            cout << err_message << endl;
        }

        //storing the content into the file.
        char *char_arr;
        char_arr = &s[0];
        file.write(char_arr, strlen(char_arr));
        file << "\n";
    }

    file.close();
    return;
}