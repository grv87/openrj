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
				OpenRJ.Database	db		=	new OpenRJ.Database(args[0], 0);
				int				index	=	0;

				for(; index < db.NumRecords; ++index)
				{
					//					Record	record	=	db.get_Item(index);
					Record	record	=	db[index];

					System.Console.WriteLine("Record-#" + index);

					foreach(OpenRJ.Field field in record)
					{
						System.Console.WriteLine("  " + field.Name + "=" + field.Value);
					}
				}
			}

			return;
		}
	}
}
