#include <iostream>
#include <string>

using namespace std;

#include "sequenceDatabase.h"

int main( /*int argc, char* argv[] */){
    string commandsFilename = "lab4-commands-short.tab";
    //string commandsFilename = "lab4-commands.tab";
    
    // Read in a filename from STDIN (or default to one)
    // If nothing is enter (really just a return) then use the listed filename.
    // Otherewise, read one from STDIN.
    char firstChar;
    string stdinFilename;
    cout << "Please enter the commands filename (or simply press return to use " << commandsFilename << ")\n";
    cin.get( firstChar);
    if( firstChar != '\n'){
        cin >> stdinFilename;
        // replace the default filename
        commandsFilename = firstChar + stdinFilename;
    }

    SequenceDatabase entries;
    cout << "Importing " << commandsFilename << endl;
    entries.importEntries( commandsFilename);
    
    return 0;
}