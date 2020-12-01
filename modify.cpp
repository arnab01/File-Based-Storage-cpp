#include <bits/stdc++.h>
using namespace std;

int line_number(string, string, int &);
fstream &GotoLine(fstream &, int);
void delete_line(string file_name, int n);
int get_lineindex(string &file_path, string &key);

void modify(string file_path)
{
    fstream file;
    file.open(file_path);

    //getting key input from user
    string key;
    string val;
    cout << " Enter the key to be modified: ";
    cin >> key;
    cout << " Enter the value for the key: ";
    cin >> val;
    cout << endl;
    // getting the line index
    int line_index = get_lineindex(file_path, key);

    if (line_index == -1)
        cout << " key does not exist \n";
    else
    {

        //getting the line from the index of the key
        GotoLine(file, line_index);
        

        string line;
        // file >> line;
        getline(file, line, '\n');
        // cout << line << endl;

        //tokenizing the string for modification and pushing the new value to file alongside the key
        vector<string> tokens;
        stringstream check1(line);
        string intermediate;
        while (getline(check1, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }

        // cout << "Tockens:\n";
        // for(auto& x : tokens) cout << x << ' ';
        // cout << '\n';

        tokens[1] = val;

        string new_info = "";

        for (int i = 0; i < 3; i++)
        {
            new_info += tokens[i];
            if (i < 2)
                new_info += " ";
        }

        //writing new information into the file

        char *char_arr;
        char_arr = &new_info[0];

        cout << " " << char_arr << endl;
        ofstream file_2;
        file_2.open(file_path, ios_base::app);
        file_2.write(char_arr, strlen(char_arr));
        file_2 << "\n";
        file_2.close();
    }

    file.close();
    delete_line(file_path, line_index);
    return;
}