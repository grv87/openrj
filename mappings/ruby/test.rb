

require 'openrj'

db = OpenRJ::Database::new('../../samples/pets/pets.orj')
#db = OpenRJ::Database::new('H:\freelibs\openrj\bin\wp_bust_2.txt', 0)

puts "Num lines:   " + String(db.numLines)
puts "Num fields:  " + String(db.numFields)
puts "Num records: " + String(db.numRecords)

db.each \
{ |r|
		puts "  Record:"
		r.each \
		{ |f|
				puts f
		}
}
		
puts "Finished"

