#include <iostream>

#include <file_reader.h>

int main (int argc, char* argv[]) {
    FileReader* reader = new FileReader(false);
    bool outcome = reader->readFile("data/test.txt");
    int retCode = 0;
    if(outcome == 0) {
        cerr << "[main] unable to locate [data/test.txt]" << endl;
        cerr << "[main] lunch from the project root" << endl;
        retCode = -1;
    }else {
        cout << "[main] file read outcome [" << outcome << "]" << endl;
        reader->tokenize();
        reader->printContent();
        reader->reverseListTokens();
    }

    delete reader;

    return retCode;
}
