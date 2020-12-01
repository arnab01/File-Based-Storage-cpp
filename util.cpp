#include <bits/stdc++.h>
using namespace std;

//seeking pointer to a particular line in a file
fstream &GotoLine(fstream &file, int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

//getting line number for a given key
int line_number(string x, string key, int &y)
{
    y++;
    vector<string> tokens;
    stringstream check1(x);
    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    //cout<<"tokens"<<" "<<tokens[0]<<" "<<tokens[1]<<" "<<tokens[2]<<endl;
    if (key == tokens[0])
    {
        return y;
    }
    else
        return -1;
}

//check function for key match
string check(string x, string key)
{

    //tokenizing the string
    vector<string> tokens;
    stringstream check1(x);
    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    //cout<<"tokens"<<" "<<tokens[0]<<" "<<tokens[1]<<" "<<tokens[2]<<endl;
    if (key == tokens[0])
    {
        return tokens[1];
    }
    else
        return "";
}

// an utilizable delete line function to delete a given line number from a file
void delete_line(string file_name, int n)
{
    ifstream is(file_name);

    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char *file_arr;
    file_arr = &file_name[0];

    cout << "path : " << file_arr << endl;
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (line_no != n)
            ofs << c;

        if (c == '\n')
            line_no++;
    }

    ofs.close();
    is.close();

    if (remove(file_arr) == 0)
        cout << "success" << endl;
    else
        cout << "not done" << endl;

    rename("temp.txt", file_arr);
}

// A utility funciton to get the index of a particular key
int get_lineindex(string &file_path, string &key)
{
    int y = 0;
    fstream file;
    file.open(file_path);

    //getting key input from user
    int line_index = -1;
    //reading through the file
    if (file.is_open())
    {
        string tp;
        while (getline(file, tp))
        { //read data from file object and put it into string.
            int c = line_number(tp, key, y);
            if (c != -1)
            {
                line_index = c;
                break;
            }
        }
    }
    return line_index;
}

bool input_check(const string &file_path, const string &s, string *err_message)
{
    ifstream in_file(file_path, ios::binary);
    in_file.seekg(0, ios::end);
    int file_size = in_file.tellg();
    int input_size = s.size();
    vector<string> tokens;
    stringstream check1(s);
    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    if (file_size + input_size > 1024 * 1024 * 1024)
    {
        *err_message = " File size limit exceeded";
        return false;
    }
    //checking key size
    if (tokens[0].size() > 32)
    {
        *err_message = " key size exceeded limits";
        return false;
    }

    //checking value size
    if (tokens[1].size() > 1024 * 16)
    {
        *err_message = " key size exceeded limits";
        return false;
    }

    return true;
}