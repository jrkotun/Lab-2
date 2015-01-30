#include "WriteFile.h"
#include <sstream>

WriteFile* WriteFile::createWriteFile(const char* file_name)
{
   WriteFile* wf = new WriteFile;
   wf->output_file.open(file_name);
   wf->closed = false;
   return wf;
}

void WriteFile::destroyWriteFile(WriteFile* wf)
{
   wf->close(wf);
   delete wf;
}

void WriteFile::close(WriteFile* wf)
{
   if (!wf->closed)
   {
      wf->output_file.close();
      wf->closed = true;
   }
}

void WriteFile::writeLine(WriteFile* wf, String* line)
{
   if (!wf->closed && line->length() > 0)
   {
      wf->output_file << line->getText() << endl;
   }
}
