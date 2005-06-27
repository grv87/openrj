
/*
 * Created: 9th August 2004
 * Updated: 16th January 2005
 */

#include <stdio.h>
#include <openrj/openrj.h>
#include <openrj/openrj_assert.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("No argument(s) specified. Specify the full path to a database to examine\n");
    }
    else
    {
        char const          *jarFile    =   argv[1];
        ORJRC               rc;
        ORJDatabaseA const  *database;
        ORJError            error;
        IORJAllocator       *ator;

        printf("Jar file: %s\n", jarFile);

#if 1
        rc = ORJ_ReadDatabaseA(jarFile, NULL, ORJ_FLAG_ELIDEBLANKRECORDS, &database, &error);
#else /* ? 0 */
        static const char   contents[] =

            "%% Sample Open-RJ database - Cats and Dogs\n"
            "%% Created:   28th September 2004\n"
            "%% Updated:   29th September 2004\n"
            "Name:      Barney\n"
            "Species:   Dog\n"
            "Breed:     Bijon \\\n"
            "           Frieze\n"
            "%%\n"
            "Name:      Elsa\n"
            "Species:   Dog\n"
            "Breed:     Mixed\n"
            "%%\n"
            "Name:      Fluffy Kitten\n"
            "Species:   Cat\n"
            "%%\n"
            "Name:      Moet\n"
            "Species:   Dog\n"
            "Breed:     Boxer\n"
            "%%\n"
            "Name:      Rebel\n"
            "Species:   Dog\n"
            "Breed:     German \\\n"
            "           Shepherd\n"
            "%%\n"
            "Name:      Pepper\n"
            "Species:   Dog\n"
            "Breed:     Border Collie\n"
            "%%\n"
            "Name:      Samson\n"
            "Species:   Dog\n"
            "Breed:     Ridgeback\n"
            "%%\n"
            "Name:      Sheltie\n"
            "Species:   Dog\n"
            "Breed:     Shetland \\\n"
            "           Sheepdog\n"
            "%%\n"
            "Name:      Sparky\n"
            "Species:   Cat\n"
            "%%\n";

        ORJ_CreateDatabaseFromMemoryA(&contents[0], sizeof(contents), NULL, ORJ_FLAG_ELIDEBLANKRECORDS, &database, &error);
#endif /* 0 */

        if(ORJ_RC_SUCCESS != rc)
        {
            if(ORJ_RC_PARSEERROR == rc)
            {
                printf("Parse error in database: %d; %s; line %d, column %d\n", error.parseError, ORJ_GetParseErrorStringA(error.parseError), error.invalidLine, error.invalidColumn);
            }
            else
            {
                printf("Error reading database: %d; %s\n", rc, ORJ_GetErrorStringA(rc));
            }

            return 1;
        }
        else
        {
            int                 i;
            int                 j;
            int                 k;
            ORJRecordA const    *record;

            printf("Num Lines:    %d\n", database->numLines);
            printf("Num Fields:   %d\n", database->numFields);
            printf("Num Records:  %d\n", database->numRecords);

            for(i = 0; ORJ_RC_SUCCESS == ORJ_Database_GetRecordA(database, i, &record); ++i)
            {
                ORJFieldA const *field;
                char const      *firstName  =   NULL;
                char const      *firstValue =   NULL;

                printf("  Record-#%d\n", i);

                for(j = 0; ORJ_RC_SUCCESS == ORJ_Record_GetFieldA(record, j, &field); ++j)
                {
                    ORJStringA const    *name;
                    ORJStringA const    *value;

                    if(0 == (j % 2))
                    {
                        ORJ_Field_GetNameAndValueA(field, &name, &value);
                    }
                    else
                    {
                        ORJ_Field_GetNameA(field, &name);
                        ORJ_Field_GetValueA(field, &value);
                    }

                    if(NULL == firstName)
                    {
                        firstName = name->ptr;
                    }
                    if(NULL == firstValue)
                    {
                        firstValue = value->ptr;
                    }

                    printf("    Field-#%d; %.*s=%.*s\n", j, name->len, name->ptr, value->len, value->ptr);

                    openrj_assert(ORJ_Field_GetRecordA(field) == record);
                }

                field = ORJ_Record_FindFieldByNameA(record, firstName, firstValue);

                openrj_assert(NULL != field);

                openrj_assert(ORJ_Record_GetDatabaseA(record) == database);
            }

            ORJ_FreeDatabaseA(database);
        }
    }

    return 0;
}
