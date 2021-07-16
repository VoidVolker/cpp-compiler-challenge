#pragma once
#include <list>
#include <string>
#include "../NodeBase.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        class Operand : public NodeBase
        {
        public:

            unsigned int globalVar = 0;

            Operand() : NodeBase() { }

            Operand(string str, unsigned int globalVar = 0) : NodeBase(str)
            {
                this->globalVar = globalVar;
            }

            void DOTNodesAdd(GraphvizDOT* dot)
            {
                dot->Node(name, to_string(globalVar));
            }

            void DOTUniqueNodesAdd(GraphvizDOT* dot)
            {
                dot->Node(name, to_string(globalVar));
            }
        };
    }
}
