using System;
using System.IO;
using System.Xml;

namespace ETLXMLReader
{
    class Program
    {
        static void Main(string[] args)
        {
            if( args.Length == 0 )
            {
                Console.WriteLine("Provide the etl XML file");
                return;
            }

            var fileName = args[0];
            if( !File.Exists(fileName) )
            {
                Console.WriteLine("{0} file is does not exsists", fileName);
                return;
            }

            var xmlTextReader = new XmlDocument();
            xmlTextReader.Load(fileName);
            int count = 0;

            foreach( var childNode in xmlTextReader.DocumentElement.ChildNodes)
            {
                count++;
            }

            Console.WriteLine("{0} event processes", count);
        }
    }
}
