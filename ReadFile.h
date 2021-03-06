#if !defined READ_FILE
#define READ_FILE

#include "Text.h"

#include <fstream>
using namespace std;

class ReadFile
{
    public:
      ifstream input_file;
      bool _eof;
      bool closed;
      ReadFile* createReadFile(const char* file_name);
      String* readLine(ReadFile* rf);
      void destroyReadFile(ReadFile* rf);
      bool eof(ReadFile* rf);
      void close(ReadFile* rf);
};

#endif
