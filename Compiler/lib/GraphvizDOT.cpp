#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;


namespace Compiler {
    class GraphvizDOT
    {
    public:
        inline static unsigned long long default_level = 0;
        inline static unsigned long long default_spaces = 4;
        inline static unsigned long long default_isStrict = false;

        string result;
        unsigned long long level = 0;
        unsigned long long spaces = 4;
        bool isDigraph = false;

        GraphvizDOT() : GraphvizDOT(default_level, default_spaces, default_isStrict) {}

        //GraphvizDOT(int level) : GraphvizDOT(level, default_spaces, default_isStrict) {}
        //GraphvizDOT(int level, int spaces) : GraphvizDOT(level, spaces, default_isStrict) {}
        //GraphvizDOT(bool isStrict) : GraphvizDOT(default_level, default_spaces, isStrict) {}

        GraphvizDOT(unsigned long long level, unsigned long long spaces, bool isStrict)
        {
            if (isStrict) {
                result += "strict ";
            }
        }

        void Add(string str) {
            result += string(level * spaces, ' ') + str;
        }
        void AddLine(string str) {
            Add(str + "\n");
        }

        void DigraphStart(string label = "") {
            BlockStart("digraph", label);
            isDigraph = true;
        }

        void GraphStart(string label = "") {
            BlockStart("graph", label);
        }

        void SubGraphStart(string label = "") {
            BlockStart("subgraph", label);
        }

        void BlockStart(string blockType, string label = "") {
            if (blockType.length() > 0) {
                Add(blockType + " {\n");
            }
            else 
            {
                Add("{\n");
            }

            level++;

            if (label.length() > 0) {
                AddLine(Attribute("label", label));
            }
        }
        
        string Attribute(string attr, string value)
        {
            return attr + "=\"" + value + "\"";
        }

        void BlockEnd() {
            level--;
            Add("}\n");
        }

        void Node(string a, string b) {
            Add("\"" + a + "\"" + NodeLink() + "\"" + b + "\"\n");
        }
        
        void Node(string a, string b, string label) {
            Add("\"" + a + "\"" + NodeLink() + "\"" + b + "\" [" + Attribute("label", label) + "]\n");
        }

        string NodeLink() {
            return isDigraph ? " -> " : " -- ";
        }
    };
}