
import std.gc;
import std.openrj;

int main(char[][] args)
{
	if(args.length < 2)
	{
		usage();
	}
	else
	{
		char[]		jarName	=	args[1];
		Database	db		=	new Database(jarName);
		char[]		name;
		char[]		value;

		printf("Fields by record:\n");

		foreach(Record record; db)
		{
			printf("record (%d fields)\n", record.length);

			foreach(Field field; record)
			{
				printf("  field: [%.*s]:[%.*s]\n", field.name, field.value);
			}
		}

		printf("All fields:\n");

		foreach(Field field; db.fields())
		{
			printf("  field: [%.*s]:[%.*s]\n", field.name, field.value);

			if(null === name)
			{
				name = field.name;
			}
		}

		name	=	"Title";
		value	=	"Taming CoInitializeSecurity";

		printf("Searching for records containing field with name: %.*s\n", name);

		foreach(Record record; db.getRecordsContainingField(name, value))
		{
			printf("record %p (%d fields)\n", record, record.length);

			foreach(Field field; record)
			{
				printf("  field: [%.*s]:[%.*s]\n", field.name, field.value);
			}
		}

/+
		for(int i = 0; i < 10000; ++i)
		{
			std.gc.fullCollect();
		}

		printf("Leaving\n");
+/
	}

	return 0;
}

private void usage()
{
	printf("USAGE: openrj_test <jarName>\n");
}
