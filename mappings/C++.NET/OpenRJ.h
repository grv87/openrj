// OpenRJ.h

#pragma once

#include <openrj/openrj.h>

namespace OpenRJ
{
	enum ORJRC
	{
			Success					=	::openrj::ORJ_RC_SUCCESS                          /*!< Operation was successful                                   */
		,   CannotOpenJarFile		=	::openrj::ORJ_RC_CANNOTOPENJARFILE                /*!< The given file does not exist, or cannot be accessed       */
		,   NoRecords				=	::openrj::ORJ_RC_NORECORDS                        /*!< The database file contained no records                     */
		,   OutOfMemory				=	::openrj::ORJ_RC_OUTOFMEMORY                      /*!< The API suffered memory exhaustion                         */
		,   BadFileRead				=	::openrj::ORJ_RC_BADFILEREAD                      /*!< A read operation failed                                    */
		,   ParseError				=	::openrj::ORJ_RC_PARSEERROR                       /*!< Parsing of the database file failed due to a syntax error  */
		,   InvalidIndex			=	::openrj::ORJ_RC_INVALIDINDEX                     /*!< An invalid index was specified                             */
		,   Unexpected				=	::openrj::ORJ_RC_UNEXPECTED                       /*!< An unexpected condition was encountered                    */
		,   InvalidContent			=	::openrj::ORJ_RC_INVALIDCONTENT                   /*!< The database file contained invalid content                */
	};
	typedef enum ORJRC		RC;

	enum PARSE_ERROR
	{
			ParseSuccess			=	::openrj::ORJ_PARSE_SUCCESS                       /*!< Parsing was successful                                                         */
		,   RecordSeparatorInContinuation				=	::openrj::ORJ_PARSE_RECORDSEPARATORINCONTINUATION /*!< A record separator was encountered during a content line continuation          */
		,   UnfinishedLine			=	::openrj::ORJ_PARSE_UNFINISHEDLINE                /*!< The last line in the database was not terminated by a line-feed                */
		,   UnfinishedField			=	::openrj::ORJ_PARSE_UNFINISHEDFIELD               /*!< The last record in the database file was not terminated by a record separator  */
		,   UnfinishedRecord		=	::openrj::ORJ_PARSE_UNFINISHEDRECORD              /*!< The last record in the database file was not terminated by a record separator  */
	};
	typedef enum PARSE_ERROR	PARSE_ERROR;

	inline RC ErrAsEnum(::openrj::ORJRC error)
	{
		return (RC)error;
	}

	inline PARSE_ERROR ErrAsEnum(::openrj::ORJ_PARSE_ERROR error)
	{
		return (PARSE_ERROR)error;
	}

} // namespace OpenRJ