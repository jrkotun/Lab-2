#include "ReadFile.h"
#include <iostream>
#include <string>

ReadFile::ReadFile(const char* file_name)
{
   input_file.open(file_name);
   closed = false;
   _eof = false;
}

ReadFile::~ReadFile()
{
   delete input_file;
}

bool ReadFile::eof()
{
   return _eof;
}

void ReadFile::close()
{
   if (input_file.is_open())
   {
      input_file.close();
      closed = true;
   }
}

String* readLine()
{
   if (closed == true) return NULL;
   if (_eof == true) return NULL;

   string text;
   _eof = !(getline(input_file.get(), text));

   String* str = new String((const char*) text.c_str());
   return str;
}
