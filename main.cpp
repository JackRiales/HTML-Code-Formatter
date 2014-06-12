#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char * argv[])
{
    // Header
    cout << "HTML Code Formatter | Written by Jack Riales for Web Operations" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "Welcome to the HTML code formatter!" << endl;
    cout << "Please provide a directory to the HTML, ASP, or PHP file you wish to format." << endl;
    cout << "Directory: ";

    string directory;
    getline(cin , directory);

    cout << "Please enter a name for this file: ";
    string name;
    getline(cin , name);
    // / Header

    // User check
    bool confirm=false;
    while(!confirm)
    {
        cout << "Format the file at " << directory << "? [y/n]: ";
        std::string choice;

        cin >> choice;
        if(choice=="y")
        {
            confirm=true;
            cout << endl;
        }
        else if(choice=="n")
        {
            cout << endl << endl;
            return 0;
        }
        else
        {
            cout << "Invalid!" << endl << endl;
            return -1;
        }
    }
    // / User check

    ifstream ifile(directory.c_str());
    if(ifile.is_open())
    {
        // Get length of the file and store in a readable buffer
        istream_iterator<char> start(ifile), end;
        cout << "Seeking file size..." << endl;
        vector<char> buffer(start, end);

        // Iterate through the buffer and seek the following: '<'
        // Behind those, insert a line break
        cout << "Formatting..." << endl;
        for(unsigned int i=0; i < buffer.size(); ++i)
        {
            cout << "ITERATION AT " << i << endl;
            if(buffer[i]=='<')
            {
                buffer.insert(buffer.begin() + i, '\n');
                i+=1;
            }
        }

        // Reinput the buffer into the file
        cout << "Writing to new file..." << endl;
        ofstream ofile( name.c_str() );
        if(ofile.is_open())
        {
            for(int i = 0; i < buffer.size(); i++)
            {
                ofile << buffer[i];
            }
            cout << "Done!" << endl;
        }
        else cout << "Error creating file!" << endlŔ;

        // Close the input file
        ifile.close();
    }
    else cout << "Cannot open file!" << endl;

    return 0;
}
