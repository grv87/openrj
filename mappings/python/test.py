
import openrj
from sys import exit

def dumpRecord(record):
	print "  record:", "#fields:", len(record), "{",
	for field in record:
		print field.name() + "=" + field.value() + ",",
	print "}"

def dumpRecordByIndex(record):
	print "  record-#" + str(i) + ":", "#fields:", len(record), "{",
	for j in range(len(record)):
		field = record[j]
		print "#" + str(j) + ":",
		print field.name() + "=" + field.value() + ",", 
	print "}"

def dumpRecordSlice(record):
	l	=	len(record)
	print "record length:", l
	for i in range(l):
		for j in range(i, l + 1):
			print "slice[" + str(i) + ":" + str(j) + "]"
			print "{", 
			for field in record[i:j]:
				print field.name() + "=" + field.value() + ",",
			print "}"


#db = openrj.open("../../samples/pets/pets.orj", openrj.ELIDE_BLANK_RECORDS | openrj.ORDER_FIELDS)

contents = 									\
										\
		"%% Sample Open-RJ database - Cats and Dogs" 		"\n"	\
		"%% Created:   28th September 2004"			"\n"	\
		"%% Updated:   29th September 2004"			"\n"	\
		"Name:		Barney"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Bijon \\"				"\n"	\
		"			Frieze"				"\n"	\
		"%%"							"\n"	\
		"Name:		Elsa"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Mixed"					"\n"	\
		"%%"							"\n"	\
		"Name:		Fluffy Kitten"				"\n"	\
		"Species:	Cat"					"\n"	\
		"%%"							"\n"	\
		"Name:		Moet"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Boxer"					"\n"	\
		"%%"							"\n"	\
		"Name:		Rebel"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		German \\"				"\n"	\
		"			Shepherd"			"\n"	\
		"%%"							"\n"	\
		"Name:		Pepper"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Border Collie"				"\n"	\
		"%%"							"\n"	\
		"Name:		Samson"					"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Ridgeback"				"\n"	\
		"%%"							"\n"	\
		"Name:		Sheltie"				"\n"	\
		"Species:	Dog"					"\n"	\
		"Breed:		Shetland \\"				"\n"	\
		"			Sheepdog"			"\n"	\
		"%%"							"\n"	\
		"Name:		Sparky"					"\n"	\
		"Species:	Cat"					"\n"	\
		"%%\n"

db = openrj.open_memory(contents, openrj.ELIDE_BLANK_RECORDS | openrj.ORDER_FIELDS)

print "Open-RJ version:        " + openrj.__openrj_version__
print "Open-RJ/Python version: " + openrj.__version__

print db

print "Database path:", db.path()
print "Num records:  ", db.numRecords()
print "Num fields:   ", db.numFields()
print "Num lines:    ", db.numLines()


#### Enumeration #1

print ""
print "Enumerating " + str(len(db)) + " records and their fields in database via 'for'"
for record in db:
	dumpRecord(record)

#### Enumeration #2

print ""
print "Enumerating " + str(len(db)) + " records in database via integer index"
for i in range(len(db)):
	record = db[i]
	dumpRecordByIndex(record)

#### Enumeration #3

print ""
print "Enumerating fields, without records"
print "  database:", "#fields:", db.numFields(), "{",
for field in db.fields():
	print field.name() + "=" + field.value() + ",",
print "}"

exit(0)

#### Enumeration #4

if len(db) > 2:

	print ""
	print "Enumerating records slice [2:" + str(len(db)) + "]"

	for record in db[2:len(db)]:
		dumpRecordSlice(record)

