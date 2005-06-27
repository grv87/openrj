# File:     each.rb
#
# Purpose:  Shows how to enumerate the contents of a database via each()
#
# Created:  28th September 2004
# Updated:  28th September 2004

require 'openrj'

flags = OpenRJ::ELIDE_BLANK_RECORDS
db = OpenRJ::Database::new("../pets.orj", flags)

puts "Database details:"
puts "  " + String(db)

puts "Enumerating records: "
index = 0
db.each \
{ |record|
	puts "  ##{index}: " + String(record)

	index = 1 + index
}

puts "Enumerating fields: "
index = 0
db.each_field \
{ |field|
	puts "  ##{index}: " + String(field)
	index = 1 + index
}


puts "Enumerating records and fields: "
index = 0
db.each \
{ |record|
	puts "  ##{index}: " + String(record)
	fieldIndex = 0
	record.each \
	{ |field|
		puts "    ##{fieldIndex}: " + String(field)

		fieldIndex = 1 + fieldIndex
	}
	
	index = 1 + index
}


