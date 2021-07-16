#pragma once
#include <list>
#include "../NodeBase.cpp"
#include "Operand.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        class Instruction : public NodeBase
        {
        public:
            /// <summary>
            /// Instructions list
            /// </summary>
            list<Operand*> operands;

            Instruction() : NodeBase() { }

            Instruction(string str) : NodeBase(str) { }

            /// <summary>
            /// Add new operand
            /// </summary>
            /// <param name="tag"></param>
            /// <param name="blockName"></param>
            /// <returns></returns>
            Operand* NewOperand(string operandName, unsigned int globalVar = 0)
            {
                Operand* o = new Operand(operandName, globalVar);
                operands.push_back(o);
                return o;
            }

            void DOTNodesAdd(GraphvizDOT* dot)
            {
                for (auto& o : operands)
                {
                    dot->Node(name, o->name);
                    o->DOTNodesAdd(dot);
                }
            }

        };
    }
}
