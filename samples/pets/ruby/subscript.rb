# File:     subscript.rb
#
# Purpose:  Shows how to enumerate the contents of a database via []
#
# Created:  28th September 2004
# Updated:  28th September 2004

require 'openrj'

flags = OpenRJ::ELIDE_BLANK_RECORDS
db = OpenRJ::Database::new("../pets.orj", flags)

puts
puts "Database details:"
puts "  " + String(db)

puts
puts "Enumerating records: "
for i in 0 .. (db.numRecords - 1)
	record = db[i]
	puts "  ##{i}: " + String(record)
end

puts
puts "Enumerating records and fields: "
for i in 0 .. db.numRecords - 1
	record = db[i]
	puts "  ##{i}: " + String(record)
	for j in 0 .. record.numFields - 1
		field = record[j]
		puts "    ##{j}: " + String(field)
	end
end

puts
puts "Printing out the Name and Species via the [<string>] operator: "
db.each \
{ |record|
	puts "  Name:    " + record["Name"]
	puts "  Species: " + record["Species"]
	puts
}


