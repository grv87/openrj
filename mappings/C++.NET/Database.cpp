// Implementation file for OpenRJ::Database class

#include "stdafx.h"

#include "Database.h"
#include "Record.h"
#include "DatabaseException.h"

namespace OpenRJ
{
	namespace
	{
		void	*_fnAlloc(::openrj::IORJAllocator *m, size_t cb)
		{
			return NULL;
		}
		void	*_fnRealloc(::openrj::IORJAllocator *m, void *pv, size_t cb)
		{
			return NULL;
		}
		void	_fnFree(::openrj::IORJAllocator *m, void *pv)
		{
		}

		::openrj::ORJDatabaseA const *create_database_(char const *jarName, unsigned flags)
		{
			::openrj::IORJAllocator	allocator_ = 
			{
					_fnAlloc
				,	_fnRealloc
				,	_fnFree
			};
			::openrj::IORJAllocator	*allocator	=	0; // &allocator_;

			::openrj::ORJDatabaseA const	*database;
			::openrj::ORJError				error;
			::openrj::ORJRC					rc	=	::openrj::ORJ_ReadDatabaseA(jarName, allocator, flags, &database, &error);

			if(::openrj::ORJ_RC_SUCCESS != rc)
			{
				// throw something here
				throw new DatabaseException(rc, error);
			}

			return database;
		}
	}

	Database::Database(String *path, unsigned int flags)
		: m_database(create_database_(::dotnetstl::c_string_accessor<char>(path), flags))
		, m_records(NULL)
	{
		m_records	=	new ArrayList(m_database->numRecords);

		::openrj::ORJRecordA const	*begin	=	&m_database->records[0];
		::openrj::ORJRecordA const	*end	=	&m_database->records[m_database->numRecords];

		for(; begin != end; ++begin)
		{
			m_records->Add(new Record(begin, this));
		}
	}

	Database::~Database()
	{
		Close();
	}

	void Database::Close()
	{
		if(NULL != m_database)
		{
			::openrj::ORJ_FreeDatabaseA(m_database);

			m_database = NULL;
		}
	}

	void Database::Dispose()
	{
		Close();
	}

	String *Database::get_Path()
	{
		return 0;
	}

	int Database::get_NumLines()
	{
		return m_database->numLines;
	}

	int Database::get_NumFields()
	{
		return m_database->numFields;
	}

	int Database::get_NumRecords()
	{
		return m_database->numRecords;
	}

	IEnumerator *Database::GetEnumerator()
	{
		return new ::dotnetstl::ArrayListEnumerator(m_records);
	}

	Record *Database::get_Item(int index)
	{
		if(	index < 0 ||
			!(index < get_NumRecords()))
		{
			throw new IndexOutOfRangeException();
		}

		return static_cast<Record*>(m_records->get_Item(index));
	}

	String *Database::ToString()
	{
		return String::Concat(new String("Open-RJ Database; path="), get_Path());
	}

}
