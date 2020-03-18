using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LuaInterface;
using System.IO;
namespace TSLLuaConverter
{
    class Program
    {

        public static string xmlfile = "mapinfo.json";
        public static List<string> xmlContents = new List<string>();
        public static string tablebase = "";
        static void Main(string[] args)
        {
            Lua lua = new Lua();
            var result = lua.DoFile("XmlConfigManager.lua");

            string luaCode = System.IO.File.ReadAllText("XmlConfigManager.lua");
            tablebase = "runes";
            ProcessTableToFile(lua.GetTable("XmlConfigManager.scenesinfo"), 0, tablebase);

            File.WriteAllLines(xmlfile, xmlContents.ToArray());
            Console.ReadKey();
        }
        private static void ProcessTable(LuaTable t, int depth, string header)
        {
            depth++;
            //Console.WriteLine("<mapinfo ");//;   // Creates breaks between the items
            foreach (DictionaryEntry d in t)
            {
                if (d.Value.GetType() == typeof(LuaTable))
                {
                    //Console.Write(":" + header + " ");//;   // Creates breaks between the items
                    Console.WriteLine("\""+d.Key +"\" :");
                    Console.WriteLine("{");
                    ProcessTable((LuaTable)d.Value, depth, header);
                }
                else
                {
                    Console.WriteLine(String.Format("\t\"{0}\" : \"{1}\",", d.Key, d.Value));
                }
            }
            Console.Write("},");
            Console.WriteLine();//);
            Console.WriteLine();
        }

        private static void ProcessTableToFile(LuaTable t, int depth, string header)
        {
            depth++;
            //Console.WriteLine("<mapinfo ");//;   // Creates breaks between the items
            foreach (DictionaryEntry d in t)
            {
                if (d.Value.GetType() == typeof(LuaTable))
                {
                    

                    string cont = "\"" + d.Key + "\" :";
                    xmlContents.Add(cont);
                    xmlContents.Add("{");
                    ProcessTableToFile((LuaTable)d.Value, depth, header);
                }
                else
                {
                    string c2 = String.Format("\t\"{0}\" : \"{1}\",", d.Key, d.Value);
                    xmlContents.Add(c2);
                }
            }
            xmlContents.Add("},");
            xmlContents.Add("");
        }

    }
}
