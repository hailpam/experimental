/**
 * @file file_reader.h
 *
 * File Reader facility. It reads a file and provides a tokenization service.
 * Tokens can be read in natural or reverse order.
 *
 * @brief
 *
 * @author Paolo Maresca <plo.maresca@gmail.com>
 * @version 0.1
 */
// $Log$

#ifndef _FILE_READER_H
#define _FILE_READER_H

#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <list>
#include <iostream>

using namespace std;

class FileReader
{
    public:
        /**
         * Default Constructor.
         */
        FileReader();
        /**
         * Constructor with 1 argument: debug level.
         *
         * @param   isDebug     True whether the debug is activated
         */
        FileReader(bool isDebug);
        /**
         * Default Distructor.
         */
        ~FileReader();
        /**
         * Read file.
         *
         * @param fileName  Absolute identifier
         *
         * @return True iff the file has successfully read
         */
        bool readFile(const char* fileName);
        /**
         * Print the content.
         */
        void printContent();
        /**
         * Tokenize the stream read from file.
         */
        void tokenize();
        /**
         * List the tokens.
         */
        void listTokens();
        /**
         * Inverse list the tokens.
         */
        void reverseListTokens();
        /**
         * Set the token.
         */
        void setToken(const char& token);

    private:
        bool isDebug;
        bool inited;
        char token;
        stringstream content;
        set<char> toBeStripped;
        list<string> tokens;
};

#endif  /* _FILE_READER_H */
