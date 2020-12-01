#include <bits/stdc++.h>
using namespace std;

bool input_check(const string &, const string &, string *);

//adding two big numbers
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
}

//inserting into a file
void insert(string file_path)
{
    //opening the file
    ofstream file;
    file.open(file_path, ios_base::app);

    if (!file)
    { // file couldn't be opened error
        cout << " Error: file could not be opened" << endl;
        return;
    }

    else
    {

        //getting key-value content from the user
        string s;

        cout << " Enter content : ";
        cin.ignore();
        getline(cin, s);

        istringstream ss(s);
        string key;
        string value;
        string ttl;

        getline(ss, key, ' ');
        getline(ss, value, ' ');
        getline(ss, ttl, ' ');

        if (ttl.empty())
            ttl = to_string(24 * 3600); //default taking upper limit of time as 1 day for running unit test.

        string absolute_ttl = findSum(to_string(time(NULL)), ttl);

        // input size cap validation
        string err_message;
        if (!input_check(file_path, s, &err_message))
        {
            cout << err_message << endl;
            return;
        }

        s = key + " " + value + " " + absolute_ttl;
        //storing the content into the file.
        char *char_arr;
        char_arr = &s[0];
        file.write(char_arr, strlen(char_arr));
        file << "\n";
    }

    file.close();
    return;
}