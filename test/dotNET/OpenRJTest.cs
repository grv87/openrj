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
				try
				{
					Database	db		=	new Database(args[0], 2);
					int			index	=	0;

					for(; index < db.NumRecords; ++index)
					{
						Record	record	=	db[index];

						System.Console.WriteLine("Record-#" + index);

						foreach(Field field in record)
						{
							Field	field2	=	record[field.Name];

							System.Console.WriteLine("  " + field2/*.Name + "=" + field2.Value*/);
						}
					}
				}
				catch(Exception x)
				{
					System.Console.WriteLine(x);
				}
			}

			return;
		}
	}
}
