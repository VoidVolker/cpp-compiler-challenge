#pragma once
#include <iostream>
#include "GraphvizDOT.cpp"

using namespace std;

namespace Compiler {
    class NodeBase
    {
    public:
        /// <summary>
        /// Node name
        /// </summary>
        string name;

        NodeBase() { }

        NodeBase(string nodeName)
        {
            name = nodeName;
        }

        string ToDOT(unsigned long long level = 0, unsigned long long spaces = 4)
        {
            GraphvizDOT* dot = new GraphvizDOT(level, spaces, false);

            dot->DigraphStart();
            this->DOTNodesAdd(dot);
            dot->BlockEnd();

            return dot->result;
        }

        /// <summary>
        /// Virtual method for adding child nodes
        /// </summary>
        /// <param name="dot"></param>
        virtual void DOTNodesAdd(GraphvizDOT* dot)
        {

        }

        bool operator == (NodeBase a) {
            return a.name == name;
        }

        bool operator != (NodeBase a) {
            return a.name != name;
        }

        bool operator > (NodeBase a) {
            return a.name > name;
        }

        bool operator < (NodeBase a) {
            return a.name < name;
        }

        bool operator >= (NodeBase a) {
            return a.name >= name;
        }

        bool operator <= (NodeBase a) {
            return a.name <= name;
        }
    };
}