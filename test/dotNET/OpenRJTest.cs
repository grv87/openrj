
#define USE_FILE_DATABASE

namespace OpenRJTest
{
	using System;
	using OpenRJ;

	/// <summary>
	/// Summary description for OpenRJTest.
	/// </summary>
	class OpenRJTest
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main(string[] args)
		{
			if(args.Length < 1)
			{
				System.Console.WriteLine("USAGE: OpenRJTest <jarFile>");
			}
			else
			{
				string	file	=	args[0];

				if(	file == "--unittest" ||
					file == "--unittests")
				{
					;
				}
				else
				{
					try
					{
#if USE_FILE_DATABASE
						Database	db			=	new FileDatabase(args[0], 2);
#else // ? USE_FILE_DATABASE
						string		contents	=	""
												+	"Name:		Barney\n"
												+	"Species:	Dog\n"
												+	"Breed:		Bijon \\\n"
												+	"			Frieze\n"
												+	"%%\n"
												+	"Name:		Elsa\n"
												+	"Species:	Dog\n"
												+	"Breed:		Mixed\n"
												+	"%%\n"
												+	"Name:		Fluffy Kitten\n"
												+	"Species:	Cat\n"
												+	"%%\n"
												+	"Name:		Moet\n"
												+	"Species:	Dog\n"
												+	"Breed:		Boxer\n"
												+	"%%\n"
												+	"Name:		Rebel\n"
												+	"Species:	Dog\n"
												+	"Breed:		German \\\n"
												+	"			Shepherd\n"
												+	"%%\n"
												+	"Name:		Pepper\n"
												+	"Species:	Dog\n"
												+	"Breed:		Border Collie\n"
												+	"%%\n"
												+	"Name:		Samson\n"
												+	"Species:	Dog\n"
												+	"Breed:		Ridgeback\n"
												+	"%%\n"
												+	"Name:		Sheltie\n"
												+	"Species:	Dog\n"
												+	"Breed:		Shetland \\\n"
												+	"			Sheepdog\n"
												+	"%%\n"
												+	"Name:		Sparky\n"
												+	"Species:	Cat\n"
												+	"%%\n";
						Database	db			=	new MemoryDatabase(contents, 2);
#endif // USE_FILE_DATABASE
						int			index	=	0;

						for(; index < db.NumRecords; ++index)
						{
							Record	record	=	db[index];

							System.Console.WriteLine("Record-#" + index);

#if USE_INT_INDEXER
							int index2	 = 0;
							for(; index2 < record.NumFields; ++index2)
#else // ? USE_INT_INDEXER
							foreach(Field field in record)
#endif // USE_INT_INDEXER
							{
#if USE_INT_INDEXER
								Field	field2	=	record[index2];
#else // ? USE_INT_INDEXER
//								String	field2	=	record[field.Name];
								Field	field2	=	record[field.Name];
#endif // USE_INT_INDEXER

								System.Console.WriteLine("  " + field2/*.Name + "=" + field2.Value*/);
							}
						}
					}
					catch(Exception x)
					{
						System.Console.WriteLine(x);
					}
				}
			}

			return;
		}
	}
}
