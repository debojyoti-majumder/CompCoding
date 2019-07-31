﻿using System;
using System.IO;
using System.Xml;
using System.Collections.Generic;

namespace ETLXMLReader
{
    class Program
    {
        // This should need to have be strongly typed, on those type LINQ can easily be used
        static private List<string> GetDebugData(XmlNode nd)
        {
            List<string> debugInfos = new List<string>();
            foreach( XmlNode n in nd.ChildNodes )
            {
                debugInfos.Add(n.InnerText);
            }

            return debugInfos;
        }

        // Outputing to console, should go out in a file
        static bool ProcessEventNode(XmlNode eventNode)
        {
            XmlNode systemNode = null;
            XmlNode debugDataNode = null;
            
            foreach( XmlNode nd in eventNode.ChildNodes )
            {
                if (nd.Name == "System") systemNode = nd;
                else if (nd.Name == "DebugData") debugDataNode = nd;
            }

            if (systemNode == null || debugDataNode == null)
                return false;

            var infos = GetDebugData(debugDataNode);

            // Ugly string outpting
            string outputOpt = "";
            foreach( string m in infos )
            {
                if (m.Length != 0)
                    outputOpt += m + " ";
            }
            Console.WriteLine(outputOpt);

            return true;
        }

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

            foreach( XmlNode childNode in xmlTextReader.DocumentElement.ChildNodes)
            {
                if( ProcessEventNode(childNode) )
                    count++;
            }

            Console.WriteLine("{0} event processes", count);
        }
    }
}
