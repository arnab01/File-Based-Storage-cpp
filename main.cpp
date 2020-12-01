
/** Run the project with:
    g++ create.cpp insert.cpp main.cpp modify.cpp read.cpp util.cpp remove.cpp update.cpp -o main -std=c++17
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void insert(string);
void read(string);
void modify(string);
void remove(string);
void update(string);
string create(string, string);

int main()
{

    cout << " \n \n \n           WELCOME TO THE FILE MANAGEMENT SYSTEM" << endl
         << endl;
    //initializing utilizable variables
    string file_path;
    string file_name;

    //creation of file
    string final_path = create(file_path, file_name);

    int choice = 1;

    while (choice != 0)
    {
        //getting user's choice of operation
        cout << endl
             << "Operations: \n 0.Exit \n 1.Insert \n 2.read \n 3.Modify \n 4.Delete \n Enter your choice: ";
        cin >> choice;

        // invoking operation based on choices
        update(final_path);
        
        switch (choice)
        {
        case 0:
            break;
        case 1:
            insert(final_path);
            break;
        case 2:
            read(final_path);
            break;
        case 3:
            modify(final_path);
            break;
        case 4:
            remove(final_path);
            break;
        default:
            cout << "Invalid input \n";
            break;
        }
    }
}