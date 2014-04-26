#include <file_reader.h>

FileReader::FileReader()
{
    this->isDebug = false;
    this->inited = false;
    this->token = ' ';
    this->toBeStripped.insert('.');
    this->toBeStripped.insert(',');
    this->toBeStripped.insert(':');
    this->toBeStripped.insert(';');
    this->toBeStripped.insert('?');
    this->toBeStripped.insert('!');
    this->toBeStripped.insert('(');
    this->toBeStripped.insert(')');
    this->toBeStripped.insert('[');
    this->toBeStripped.insert(']');
    this->toBeStripped.insert('{');
    this->toBeStripped.insert('}');
}

FileReader::FileReader(bool isDebug)
{
    this->isDebug = isDebug;
    this->inited = false;
    this->token = ' ';
    this->toBeStripped.insert('.');
    this->toBeStripped.insert(',');
    this->toBeStripped.insert(':');
    this->toBeStripped.insert(';');
    this->toBeStripped.insert('?');
    this->toBeStripped.insert('!');
    this->toBeStripped.insert('(');
    this->toBeStripped.insert(')');
    this->toBeStripped.insert('[');
    this->toBeStripped.insert(']');
    this->toBeStripped.insert('{');
    this->toBeStripped.insert('}');
}

FileReader::~FileReader()
{
    // TODO
}

bool FileReader::readFile(const char* fileName)
{
    string line;
    ifstream file(fileName);
    if(file.is_open()) {
        while(getline(file, line)) {
            this->content << line;
        }
        if(this->isDebug)
            cout << "[FileReader][readFile] content <" << this->content.str() << ">" << endl;
        file.close();
        return true;
    }else
        return false;
}

void FileReader::tokenize()
{
    // TODO : to be reworked
    string token = "";
    set<char>::iterator itr;
    for(unsigned int i = 0; i < this->content.str().length(); i++) {
        itr = this->toBeStripped.find(this->content.str()[i]);
        if(itr != this->toBeStripped.end()) {
            if(i == (this->content.str().length() - 1))
                this->tokens.push_back(token);
            continue;
        }
        if(this->content.str()[i] == this->token) {
           this->tokens.push_back(token);
           token = "";
        }else
            token = token + this->content.str()[i];
        if(this->isDebug)
            cout << "[FileReader][tokenize] char <" << this->content.str()[i] << ">, list size [" << this->tokens.size() << "]" << endl;
    }
}

void FileReader::listTokens()
{
    list<string>::iterator itr;
    for(itr = this->tokens.begin(); itr != this->tokens.end(); itr++) {
        cout << "[FileReader][listTokens] token <" << *itr << ">" << endl;
    }
}

void FileReader::reverseListTokens()
{
    list<string>::reverse_iterator itr;
    for(itr = this->tokens.rbegin(); itr != this->tokens.rend(); itr++) {
        cout << "[FileReader][reverseListTokens] token <" << *itr << ">" << endl;
    }
}

void FileReader::setToken(const char& token)
{
    this->token = token;
}

void FileReader::printContent()
{
    cout << "[FileReader][printContent] content <" << this->content.str() << ">" << endl;
}
