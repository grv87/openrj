
option explicit

dim db
set db = CreateObject("openrj.com.Database")

' wscript.echo db.DocString

dim flags
set flags = CreateObject("openrj.com.DatabaseFlags")

' wscript.echo flags.DocString

dim mem

mem = _
	"%% Sample Open-RJ database - Cats and Dogs" & vbCrLf & _
	"%% Created:  28th September 2004" & vbCrLf & _
	"%% Updated:  26th May 2006 " & vbCrLf & _
	"_OpenRJ.Field.Alias: 1:Name" & vbCrLf & _
	"_OpenRJ.Field.Alias: 2:Species" & vbCrLf & _
	"_OpenRJ.Field.Alias: 3:Breed" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Barney" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Bijon Frieze" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Elsa" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Mixed" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Fluffy Kitten" & vbCrLf & _
	"2:  Cat" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Moet" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Boxer" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Rebel" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  German \" & vbCrLf & _
	"    Shepherd" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Pepper" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Border Collie" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Samson" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Ridgeback" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Sheltie" & vbCrLf & _
	"2:  Dog" & vbCrLf & _
	"3:  Shetland \" & vbCrLf & _
	"    Sheepdog" & vbCrLf & _
	"%%" & vbCrLf & _
	"1:  Sparky" & vbCrLf & _
	"2:  Cat" & vbCrLf & _
	"%%" & vbCrLf


db.OpenMemory mem, flags.OrderFields + flags.ElideBlankRecords '+ flags.NoReinterpretFieldsIds

dim record
dim field

for each record in db
'	wscript.echo record.DocString
	wscript.echo "Record:", record.Count

	for each field in record
'		wscript.echo field.DocString
		wscript.echo "    " & field.Name & ":", field.Value
	next

next


