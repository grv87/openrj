// This sample adapted from a newsgroup post by Rajiv Bhagwat

#include <openrj/cpp/memorydatabase.hpp>
//#include <openrj/openrj_implicit_link.h> // Enable this to avoid the need to specify the lib name to the compiler
#include <iostream>
#include <string.h>

// Table taken from the original sample ..
const char contents[] = "%% Sample Open-RJ database - Cats and Dogs\n"
"%% Created:   28th September 2004\n"
"%% Updated:   24th May 2005\n"
"Name:  Barney\n"
"Species: Dog\n"
"%%\n"
"Name:  Sparky\n"
"Species: Cat\n"
"%%\n";

// Emit the table contents as specified by 'str'
void emit(const char *contents)
{
    using namespace openrj::cpp;

    MemoryDatabase db(contents, ::strlen(contents));

	for(size_t i1 = 0; i1 < db.GetNumRecords(); ++i1) // Loop over the records
	{
		Record	record(db[i1]);

        std::cout << record.GetComment() << std::endl;

        for(size_t i2 = 0; i2 < record.GetNumFields(); ++i2) // Loop over the fields
        {
            std::cout << record[i2].GetName() << "= '" << record[i2].GetValue() << "'" << std::endl;
        }
        std::cout << std::endl;
   }
}

int main()
{
	try
	{
       emit(contents);  // from memory
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;

        return 1;
    }

	return 0;
}
