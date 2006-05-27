################################################################################
# File:     makefile
#
# Purpose:  Creates the documentation and prepares the distribution
#           for the Open-RJ project
#
# Created:  3rd March 2005
# Updated:  28th May 2006
# 
################################################################################

!ifndef OPENRJ_VER
! error OPENRJ_VER must be defined, e.g. "1.2.1"
!endif # OPENRJ_VER

!ifndef OPENRJ_ROOT
! ifndef OPENRJ_DEV
!  error OPENRJ_DEV environment variable not defined
! endif # OPENRJ_DEV
OPENRJ_ROOT			=	$(OPENRJ_DEV)
!endif # OPENRJ_ROOT

DOCC				=	doxygen
ZIP					=	wzzip

INTCOPY				=	intcopy.exe
INTCOPY_ARGS		=	-O -f

PROJ_VER			=	$(OPENRJ_VER)
PROJ_TAG			=	openrj
PROJ_NAME			=	Open-RJ
PROJ_DIR			=	current

PROJ_BASE_DIR		=	H:\freelibs\openrj

PROJ_ROOT_DIR		=	$(PROJ_BASE_DIR)\$(PROJ_DIR)
PROJ_PROCESSING_DIR	=	$(PROJ_ROOT_DIR)\_internal
PROJ_DOC_ROOT_DIR	=	$(PROJ_ROOT_DIR)\doc
PROJ_SRC_DIR		=	$(PROJ_ROOT_DIR)\src
PROJ_BUILD_DIR		=	$(PROJ_ROOT_DIR)\build
PROJ_INCLUDE_DIR	=	$(PROJ_ROOT_DIR)\include
PROJ_TEST_DIR		=	$(PROJ_ROOT_DIR)\test
PROJ_EXAMPLES_DIR	=	$(PROJ_ROOT_DIR)\examples
PROJ_DISTINFO_DIR	=	$(PROJ_PROCESSING_DIR)\dist-src

PROJ_DOC_SRC_DIR	=	$(PROJ_PROCESSING_DIR)\doc-src
PROJ_IMAGES_DIR		=	$(PROJ_PROCESSING_DIR)\images

PROJ_DOC_HELP_DIR	=	$(PROJ_DOC_ROOT_DIR)
#PROJ_DOC_OUTPUT_DIR	=	$(PROJ_DOC_HELP_DIR)\$(PROJ_VER)
PROJ_DOC_OUTPUT_DIR	=	$(PROJ_DOC_HELP_DIR)\html

ZIP_ARGS			=	-a -ex -o -ybc -P
ZIP_ARGS_NON_REC	=	-a -ex -o -ybc

SRCS_HEADERS		= \
 $(PROJ_INCLUDE_DIR)\openrj\openrj.h \
 $(PROJ_INCLUDE_DIR)\openrj\openrj_assert.h \
 \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrjfwd.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrj.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\database.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\databasebase.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\field.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\filedatabase.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\functions.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\memorydatabase.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\record.hpp \
 \
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrjfwd.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrj.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\database.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\field.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\functional.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\iterator.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\record.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\utility.hpp \
 \

SRCS_IMPLS			= \
 $(PROJ_SRC_DIR)\orjapi.c \
 $(PROJ_SRC_DIR)\orjmem.c \
 $(PROJ_SRC_DIR)\orjstr.c \
 \

HEADER_HTML			=	$(PROJ_DOC_SRC_DIR)\$(PROJ_TAG).header.html
FOOTER_HTML			=	$(PROJ_DOC_SRC_DIR)\$(PROJ_TAG).footer.html
STYLE_SHEET			=	$(PROJ_DOC_SRC_DIR)\$(PROJ_TAG).css
MAINPAGE_SRC		=	$(PROJ_DOC_SRC_DIR)\mainpage.src

IMAGE_NAME_CUJ		=	cuj_logo.gif
IMAGE_NAME_OPENRJ	=	openrj_logo_small.jpg
IMAGE_NAME_SYNSOFT	=	syn_head.jpg
IMAGE_NAME_STLSOFT	=	stlsoft200x100.jpg

IMAGE_CUJ			=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_CUJ)
IMAGE_SYNSOFT		=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_SYNSOFT)
IMAGE_STLSOFT		=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_STLSOFT)
IMAGE_COMSTL		=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_COMSTL)
IMAGE_UNIXSTL		=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_UNIXSTL)
IMAGE_WINSTL		=	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_WINSTL)

SRCS_DOCS			= \
 $(HEADER_HTML) \
 $(FOOTER_HTML) \
 $(STYLE_SHEET) \
 $(MAINPAGE_SRC) \
 \
 
SRCS				= \
 $(SRCS_HEADERS) \
 $(SRCS_IMPLS) \
 $(SRCS_DOCS) \
 \

DIST_INFO_SRCS =\
 $(PROJ_DISTINFO_DIR)\AUTHORS.txt \
 $(PROJ_DISTINFO_DIR)\CHANGES.txt \
 $(PROJ_DISTINFO_DIR)\FAQ.txt \
 $(PROJ_DISTINFO_DIR)\HISTORY.txt \
 $(PROJ_DISTINFO_DIR)\INSTALL.txt \
 $(PROJ_DISTINFO_DIR)\LICENSE.txt \
 $(PROJ_DISTINFO_DIR)\NEWS.txt \
 $(PROJ_DISTINFO_DIR)\README.txt \
 \

# Doxygen symbols

DOC_FILE_PATTERNS			= \
 *.h \
 *.hpp \
 \

# *.c \
# *.cpp \

DOC_EXCLUDE_FILE_PATTERNS =\
 extconf.rb \
 \

DOC_INPUT_DIRS_AND_FILES	= \
 $(PROJ_DOC_SRC_DIR)\mainpage.src \
 $(PROJ_INCLUDE_DIR)\openrj \
 $(PROJ_INCLUDE_DIR)\openrj\cpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl \
 $(PROJ_DOC_SRC_DIR) \
 \

# $(PROJ_SRC_DIR) \

DOC_STRIP_FROM_PATH = \
 $(PROJ_DOC_SRC_DIR) \
 $(PROJ_INCLUDE_DIR) \
 \

DOC_STRIP_FROM_INC_PATH = \
 $(PROJ_INCLUDE_DIR) \
 \

DOC_RECURSIVE				=	NO

DOC_EXCLUDE					=	

DOC_EXAMPLE_PATHS			= \
 $(PROJ_EXAMPLES_DIR)/ \
 \

DOC_EXAMPLE_PATTERNS		= \
 *.c \
 *.ch \
 *.cpp \
 *.py \
 *.rb \
 \

DOC_EXAMPLE_RECURSIVE		=	YES

DOC_PREDEFINED				= \
 _WIN32_DCOM \
 _WIN32_WINNT=0x0406 \
 _REENTRANT \
 OPENRJ_DOCUMENTATION_SKIP_SECTION \
 STLSOFT_DOCUMENTATION_SKIP_SECTION \
 __cplusplus \
 _MT \
 __STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT \
 STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT \
 __STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT \
 STLSOFT_CF_BIDIRECTIONAL_ITERATOR_SUPPORT \
 STLSOFT_CF_EXCEPTION_SUPPORT \
 ORJ_CALL(x)=x \
 ORJ_TAG_NAME(x)=x \
 stlsoft_ns_qual(x)=stlsoft::x \
 \

DOC_EXPAND_AS_DEFINED		= \
 OPENRJ_VER \
 ORJ_CALL \
 ORJ_TAG_NAME \
 ORJ_EXTERN_C \
 stlsoft_ns_qual \
 \

# Target names

DOXYGEN_CHM_NAME	=	$(PROJ_TAG)-$(PROJ_VER).chm

DOXYGEN_CHM_PATH	=	$(PROJ_DOC_HELP_DIR)\$(DOXYGEN_CHM_NAME)

ZIP_FILE			=	$(PROJ_ROOT_DIR)\$(PROJ_TAG)-$(PROJ_VER).zip
MD5_FILE			=	$(PROJ_ROOT_DIR)\$(PROJ_TAG)-$(PROJ_VER).md5

all:	target

usage:
	@echo "make [usage | clean | all | doc | view | target] - default is 'all'"

clean:
	@-if exist $(ZIP_FILE) del /f $(ZIP_FILE)
	@-if exist $(DOXYGEN_CHM_PATH) del /f $(DOXYGEN_CHM_PATH)

target:	$(DOXYGEN_CHM_PATH) $(ZIP_FILE) $(MD5_FILE)

view:	$(DOXYGEN_CHM_PATH)
	exec -e $(DOXYGEN_CHM_PATH)

doc:	$(DOXYGEN_CHM_PATH)

!ifndef RELEASE_NOTES
RELEASE_NOTES			=	$(PROJ_NAME)-ReleaseNotes-$(PROJ_VER).txt
!endif # RELEASE_NOTES

# Temporary files

TEMPFILE_1				=	$(PROJ_PROCESSING_DIR)\listfile-$(PROJ_VER)-1.lst
TEMPFILE_2				=	$(PROJ_PROCESSING_DIR)\listfile-$(PROJ_VER)-2.lst
TEMPFILE_3				=	$(PROJ_PROCESSING_DIR)\listfile-$(PROJ_VER)-3.lst
TEMPFILE_4				=	$(PROJ_PROCESSING_DIR)\listfile-$(PROJ_VER)-4.lst
TEMPFILE_5				=	$(PROJ_PROCESSING_DIR)\listfile-$(PROJ_VER)-5.lst

	
$(ZIP_FILE):	$(DOXYGEN_CHM_PATH) $(SRCS) $(DIST_INFO_SRCS) $(RELEASE_NOTES) makefile
	@-if exist $(ZIP_FILE) del /f $(ZIP_FILE)
	@-if exist $(TEMPFILE_1) del /f $(TEMPFILE_1)
# Release notes
	$(ZIP) $(ZIP_ARGS) $@ $(README)
	$(ZIP) $(ZIP_ARGS) $@ $(RELEASE_NOTES)
	cd ..
# C/C++ Headers and source from root directory 
	@whereis -s -t $(PROJ_ROOT_DIR) *.c;*.ch;*.chf;*.cpp;*.cs;*.csproj;*.d;*.def;*.dsp;*.dsw;*.h;*.hpp;*.ico;*.py;*.rb; >> $(TEMPFILE_1)
# Makefiles from build directory 
	@whereis -s -t $(PROJ_BUILD_DIR) makefile;makefile.win32;makefile.unix >> $(TEMPFILE_1)
# CHM file
	@whereis -s -t $(PROJ_ROOT_DIR) $(DOXYGEN_CHM_NAME) >> $(TEMPFILE_1)
# Help files for current version only
	@whereis -s -t $(PROJ_DOC_OUTPUT_DIR) *.html;*.css;*.gif;*.jpg;*.jpeg;*.png;*.js >> $(TEMPFILE_1)
# Create the zip 
	$(ZIP) $(ZIP_ARGS) $@ @$(TEMPFILE_1)
# Now add the human-readable information files
	@whereis -s -t $(PROJ_DISTINFO_DIR) *.txt > zip-src-$(PROJ_VER).lst
	$(ZIP) $(ZIP_ARGS_NON_REC) $@ @zip-src-$(PROJ_VER).lst
# Delete the temporary
	@-if exist $(TEMPFILE_1) del /f $(TEMPFILE_1)

$(MD5_FILE):	$(ZIP_FILE)
	md5 $(ZIP_FILE) > $@

# Rules for ensuring that the STLSoft / Synesis images are in the right place
$(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_CUJ):	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_CUJ)
	-if not exist "$(PROJ_DOC_ROOT_DIR)" mkdir "$(PROJ_DOC_ROOT_DIR)"
	-if not exist "$(PROJ_DOC_HELP_DIR)" mkdir "$(PROJ_DOC_HELP_DIR)"
	-if not exist "$(PROJ_DOC_OUTPUT_DIR)" mkdir "$(PROJ_DOC_OUTPUT_DIR)"
	$(INTCOPY) $(INTCOPY_ARGS) $? $@

$(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_OPENRJ):	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_OPENRJ)
	-if not exist "$(PROJ_DOC_ROOT_DIR)" mkdir "$(PROJ_DOC_ROOT_DIR)"
	-if not exist "$(PROJ_DOC_HELP_DIR)" mkdir "$(PROJ_DOC_HELP_DIR)"
	-if not exist "$(PROJ_DOC_OUTPUT_DIR)" mkdir "$(PROJ_DOC_OUTPUT_DIR)"
	$(INTCOPY) $(INTCOPY_ARGS) $? $@

$(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_SYNSOFT):	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_SYNSOFT)
	-if not exist "$(PROJ_DOC_ROOT_DIR)" mkdir "$(PROJ_DOC_ROOT_DIR)"
	-if not exist "$(PROJ_DOC_HELP_DIR)" mkdir "$(PROJ_DOC_HELP_DIR)"
	-if not exist "$(PROJ_DOC_OUTPUT_DIR)" mkdir "$(PROJ_DOC_OUTPUT_DIR)"
	$(INTCOPY) $(INTCOPY_ARGS) $? $@

$(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_STLSOFT):	$(PROJ_IMAGES_DIR)\$(IMAGE_NAME_STLSOFT)
	-if not exist "$(PROJ_DOC_ROOT_DIR)" mkdir "$(PROJ_DOC_ROOT_DIR)"
	-if not exist "$(PROJ_DOC_HELP_DIR)" mkdir "$(PROJ_DOC_HELP_DIR)"
	-if not exist "$(PROJ_DOC_OUTPUT_DIR)" mkdir "$(PROJ_DOC_OUTPUT_DIR)"
	$(INTCOPY) $(INTCOPY_ARGS) $? $@

# Generate the documentation
#
# This involves on-the-fly definition of the Doxygen file, using the nmake << syntax
$(DOXYGEN_CHM_PATH): \
 $(SRCS) \
 $(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_CUJ) \
 $(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_OPENRJ) \
 $(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_SYNSOFT) \
 $(PROJ_DOC_OUTPUT_DIR)\$(IMAGE_NAME_STLSOFT) \
 makefile
	$(DOCC) $(DOCC_ARGS) <<
# Doxyfile 1.2.17

#---------------------------------------------------------------------------
# General configuration options
PROJECT_NAME           = "$(PROJ_NAME) - Libraries"
PROJECT_NUMBER         = "Version $(PROJ_VER)"
CREATE_SUBDIRS         = NO
OUTPUT_DIRECTORY       = $(PROJ_DOC_OUTPUT_DIR)
OUTPUT_LANGUAGE        = English
EXTRACT_ALL            = NO
EXTRACT_PRIVATE        = NO
EXTRACT_STATIC         = NO
EXTRACT_LOCAL_CLASSES  = YES
HIDE_UNDOC_MEMBERS     = YES
HIDE_UNDOC_CLASSES     = YES
HIDE_FRIEND_COMPOUNDS  = YES
BRIEF_MEMBER_DESC      = YES
REPEAT_BRIEF           = YES
ALWAYS_DETAILED_SEC    = YES
INLINE_INHERITED_MEMB  = YES
FULL_PATH_NAMES        = YES
STRIP_FROM_PATH        = $(DOC_STRIP_FROM_PATH)
STRIP_FROM_INC_PATH    = $(DOC_STRIP_FROM_INC_PATH)
INTERNAL_DOCS          = NO
STRIP_CODE_COMMENTS    = YES
CASE_SENSE_NAMES       = NO
SHORT_NAMES            = NO
HIDE_SCOPE_NAMES       = YES
VERBATIM_HEADERS       = YES
SHOW_INCLUDE_FILES     = YES
JAVADOC_AUTOBRIEF      = YES
MULTILINE_CPP_IS_BRIEF = NO
DETAILS_AT_TOP         = YES
INHERIT_DOCS           = YES
INLINE_INFO            = YES
SORT_MEMBER_DOCS       = YES
DISTRIBUTE_GROUP_DOC   = NO
TAB_SIZE               = 4
GENERATE_LATEX         = NO
GENERATE_TODOLIST      = YES
GENERATE_TESTLIST      = YES
GENERATE_BUGLIST       = YES
GENERATE_DEPRECATEDLIST= YES
ALIASES                = 
ENABLED_SECTIONS       = 
MAX_INITIALIZER_LINES  = 30
OPTIMIZE_OUTPUT_FOR_C  = NO
OPTIMIZE_OUTPUT_JAVA   = NO
SHOW_USED_FILES        = YES
# configuration options related to warning and progress messages
QUIET                  = NO
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = YES
WARN_FORMAT            = "$$file($$line): $$text"
WARN_LOGFILE           = 
# configuration options related to the input files
INPUT                  = $(DOC_INPUT_DIRS_AND_FILES)
FILE_PATTERNS          = $(DOC_FILE_PATTERNS)
RECURSIVE              = $(DOC_RECURSIVE)
EXCLUDE                = $(DOC_EXCLUDE)
EXCLUDE_SYMLINKS       = NO
EXCLUDE_PATTERNS       = $(DOC_EXCLUDE_FILE_PATTERNS)
EXAMPLE_PATH           = $(DOC_EXAMPLE_PATHS)
EXAMPLE_PATTERNS       = $(DOC_EXAMPLE_PATTERNS)
EXAMPLE_RECURSIVE      = $(DOC_EXAMPLE_RECURSIVE)
IMAGE_PATH             = 
INPUT_FILTER           = 
FILTER_SOURCE_FILES    = NO
# configuration options related to source browsing
SOURCE_BROWSER         = NO
INLINE_SOURCES         = NO
REFERENCED_BY_RELATION = YES
REFERENCES_RELATION    = YES
# configuration options related to the alphabetical class index
ALPHABETICAL_INDEX     = YES
COLS_IN_ALPHA_INDEX    = 4
# configuration options related to the HTML output
GENERATE_HTML          = YES
HTML_OUTPUT            = .
HTML_FILE_EXTENSION    = .html
HTML_HEADER            = $(HEADER_HTML)
HTML_FOOTER            = $(FOOTER_HTML)
HTML_STYLESHEET        = $(STYLE_SHEET)
HTML_ALIGN_MEMBERS     = YES
GENERATE_HTMLHELP      = YES
CHM_FILE               = $(DOXYGEN_CHM_PATH)
HHC_LOCATION           = "$(HHC_PATH)"
GENERATE_CHI           = NO
BINARY_TOC             = NO
TOC_EXPAND             = YES
DISABLE_INDEX          = NO
ENUM_VALUES_PER_LINE   = 1
GENERATE_TREEVIEW      = YES
TREEVIEW_WIDTH         = 250
# configuration options for the AutoGen Definitions output
GENERATE_AUTOGEN_DEF   = NO
# Configuration options related to the preprocessor   
ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = YES
EXPAND_ONLY_PREDEF     = YES
SEARCH_INCLUDES        = YES
INCLUDE_PATH           = 
INCLUDE_FILE_PATTERNS  = 
PREDEFINED             = $(DOC_PREDEFINED)
EXPAND_AS_DEFINED      = $(DOC_EXPAND_AS_DEFINED)
SKIP_FUNCTION_MACROS   = YES
<<

