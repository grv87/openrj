
// Updated: 8th August 2005

/** \page page_gettingstarted Getting Started
 *
 * \section section_gettingstarted Getting Started
 * 
 * This section guides you to finding sample programs for your chosed language.
 * Just click on the language below, to be taken to the example programs:
 *
 * \ref section_building_core_libs | 
 * \ref section_sample_C | \ref section_sample_Ch |
 * \ref section_sample_Cpp | \ref section_sample_Python | 
 * \ref section_sample_Ruby
 *
 */
 
/** \page page_using_C Using Open-RJ in C
 *
 * \section section_building_core_libs Building the base libraries
 *
 * 1. Open a console window with appropriate environment set up for your chosen
 * compiler.
 *
 * 2. Navigate to the requesite directory under the Open-RJ build directory. For
 * example, if your compiler is Borland C/C++ 5.6, then change directory to
 * $OPENRJ_DEV/build/bc56 (where $OPENRJ_DEV is the actual directory into which
 * you have installed the Open-RJ distribution.
 *
 * 3. Execute the MAKE command. For compilers that support multiple platforms,
 * there will be multiple makefiles in the directory, e.g. makefile.mac, 
 * makefile.win32. In that case, you should stipulate the makefile, using the
 * -f flag. For others, that are one platform only, there will just be a single
 * file named makefile.
 *
 * So, to build the files and test programs for Borland
 * C/C++ 5.6, which is a Win32-only compiler you would simply execute "make".
 * Conversely, for GCC, which is supported on multiple platforms, you would
 * execute the command "make -f makefile.unix".
 *
 * \section section_sample_C Using Open-RJ in C
 *
 * Open-RJ is written in C, and expresses a C-API, so programming in C means
 * programming to the core API.
 *
 * There are two sample programs provided:
 *
 * - The \ref subsection_sample_C_C_simple "C_simple" program provides a minimal
 * example of using the Open-RJ core API, intended to get you up and running as soon
 * as possible.
 * 
 * - The \ref subsection_sample_C_C_full "C_full" program provides a full
 * example of using the Open-RJ core API, intended to demonstrate all the available
 * functionality.
 *
 * \subsection subsection_sample_C_C_simple C_simple
 *
 * This sample/test program, located in the <b>test/C_simple</b> subdirectory, shows
 * a minimal use of the API, to load a memory database (from a literal string),
 * display information about the database (\# of lines, fields, records), and then
 * enumerate the records and their constituent fields.
 *
 * It performs these tasks twice, demonstrating the use of the raw data structures,
 * and of the API functions.
 *
 * \include test/C_simple/C_simple.c
 * 
 * \subsection subsection_sample_C_C_full C_full
 *
 * This sample/test program, located in the <b>test/C_full</b> subdirectory, shows
 * a full use of the C-API, including error-handling and use of the file-database
 * function to load a file named on the command-line. It also allows the specification
 * of the ORJ_FLAG_ORDERFIELDS and/or ORJ_FLAG_ELIDEBLANKRECORDS flags, via the
 * command-line, which can moderate the database contents as expressed by the API.
 * 
 * This program has various aspects that are peripheral to the quick absorption of
 * the API, and should be examined and tested after \ref subsection_sample_C_C_simple.
 *
 * \include test/C_full/C_full.c
 */
 
/** \page page_using_Cpp Using Open-RJ in C++
 *
 * \section section_sample_Cpp Using Open-RJ in C++
 *
 * There are two Open-RJ mappings for C++:
 *
 * - <b>Open-RJ/C++</b> (in the openrj::cpp namespace) is a 'classic' mapping, i.e. the classes present a non-STL interface
 * - <b>Open-RJ/STL</b> (in the openrj::stl namespace) is an STL-like mapping
 *
 * For <b>Open-RJ/C++</b> there are two sample programs provided:
 *
 * - The \ref subsection_sample_Cpp_Cpp_simple "Cpp_simple" program provides a minimal
 * example of using the Open-RJ/C++ mapping, intended to get you up and running as soon
 * as possible.
 * 
 * - The \ref subsection_sample_Cpp_Cpp_full "Cpp_full" program provides a full
 * example of using the Open-RJ/C++ mapping, intended to demonstrate all the available
 * functionality.
 *
 * For <b>Open-RJ/STL</b> there are two sample programs provided:
 *
 * - The \ref subsection_sample_STL_STL_simple "STL_simple" program provides a minimal
 * example of using the Open-RJ/STL mapping, intended to get you up and running as soon
 * as possible.
 * 
 * - The \ref subsection_sample_STL_STL_full "STL_full" program provides a full
 * example of using the Open-RJ/STL mapping, intended to demonstrate all the available
 * functionality.
 *
 * \subsection subsection_sample_Cpp_Cpp_simple Cpp_simple
 *
 * This sample/test program, located in the <b>test/Cpp_simple</b> subdirectory, shows
 * a minimal use of the mapping, to load a memory database (from a literal string),
 * display information about the database (\# of lines, fields, records), and then
 * enumerate the records and their constituent fields.
 *
 * \include test/Cpp_simple/Cpp_simple.cpp
 * 
 * \subsection subsection_sample_Cpp_Cpp_full Cpp_full
 *
 * This sample/test program, located in the <b>test/Cpp_full</b> subdirectory, shows
 * a full use of the Cpp-API, including error-handling and use of the FileDatabase
 * class to load a file named on the command-line. It also allows the specification
 * of the ORJ_FLAG_ORDERFIELDS and/or ORJ_FLAG_ELIDEBLANKRECORDS flags, via the
 * command-line, which can moderate the database contents as expressed by the API.
 * 
 * This program has various aspects that are peripheral to the quick absorption of
 * the mapping, and should be examined and tested after \ref subsection_sample_Cpp_Cpp_simple.
 *
 * \include test/Cpp_full/Cpp_full.cpp
 *
 * \subsection subsection_sample_STL_STL_simple STL_simple
 *
 * This sample/test program, located in the <b>test/STL_simple</b> subdirectory, shows
 * a minimal use of the mapping, to load a memory database (from a literal string),
 * display information about the database (\# of lines, fields, records), and then
 * enumerate the records and their constituent fields.
 *
 * \include test/STL_simple/STL_simple.cpp
 * 
 * \subsection subsection_sample_STL_STL_full STL_full
 *
 * This sample/test program, located in the <b>test/STL_full</b> subdirectory, shows
 * a full use of the STL-API, including error-handling and use of the file_database
 * class to load a file named on the command-line. It also allows the specification
 * of the ORJ_FLAG_ORDERFIELDS and/or ORJ_FLAG_ELIDEBLANKRECORDS flags, via the
 * command-line, which can moderate the database contents as expressed by the API.
 * 
 * This program has various aspects that are peripheral to the quick absorption of
 * the mapping, and should be examined and tested after \ref subsection_sample_STL_STL_simple.
 *
 * \include test/STL_full/STL_full.cpp
 */

/** \page page_using_Ch Using Open-RJ in Ch
 *
 * \section section_sample_Ch Using Open-RJ in Ch
 *
 * &lt;To be completed&gt;
 *
 */

/** \page page_using_Python Using Open-RJ in Python
 *
 * \section section_sample_Python Using Open-RJ in Python
 *
 * &lt;To be completed&gt;
 *
 */

/** \page page_using_Ruby Using Open-RJ in Ruby
 *
 * \section section_sample_Ruby Using Open-RJ in Ruby
 *
 * &lt;To be completed&gt;
 *
 */

