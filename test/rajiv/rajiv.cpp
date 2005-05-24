// This sample adapted from a newsgroup post by Rajiv Bhagwat

#include <openrj/stl/database.hpp>
//#include <openrj/openrj_implicit_link.h> // Enable this to avoid the need to specify the lib name to the compiler
#include <iostream>

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
    using namespace openrj::stl;

    memory_database db(contents);

    for(memory_database::const_iterator ri = db.begin(); ri != db.end(); ++ri) // Loop over the records
    {
        std::cout << (*ri).comment() << std::endl;

        for(record::const_iterator fi = (*ri).begin(); fi != (*ri).end(); ++fi) // Loop over the fields
        {
            std::cout << (*fi).name() << "= '" << (*fi).value() << "'" << std::endl;
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
