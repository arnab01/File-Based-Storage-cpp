#include <fstream>
#include <iostream>
using namespace std;

void delete_line(string, int);
int get_lineindex(string &, string &);

void remove(string file_path)
{
    string key;
    cout << " Enter the ket to be deleted: ";
    cin >> key;
    cout << endl;
    int line_index = get_lineindex(file_path, key);
    if (line_index == -1)
    {
        cout << " Key does not exist\n";
        return;
    }
    delete_line(file_path, line_index);
    cout << " Successful deletion\n";
}