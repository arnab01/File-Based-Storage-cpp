#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

void delete_line(string, int);
int get_lineindex(string &, string &);

//updating file by removing expired keys based on time-to-live
void update(string file_path)
{
    fstream newfile;
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char *file_arr;
    file_arr = &file_path[0];

    newfile.open(file_path, ios::in);
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            istringstream ss(tp);
            string ttl;
            string key;
            getline(ss, key, ' ');
            getline(ss, ttl, ' ');
            getline(ss, ttl, ' ');

            //registering the current time
            time_t current_time;
            current_time = time(NULL);
            string ts = to_string(current_time);

            // cout << "Time: " << ttl << ' ' << ts << endl;
         
            if (ttl > ts)
            {
                char *char_arr;
                char_arr = &tp[0];
                ofs.write(char_arr, strlen(char_arr));
                ofs << "\n";
            }
        }

        ofs.close();
        newfile.close();

        remove(file_arr);
        rename("temp.txt", file_arr);
    }
    else {
        cout << "Error\n";
    }
}