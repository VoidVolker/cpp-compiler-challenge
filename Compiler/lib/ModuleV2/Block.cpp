#pragma once
#include <list>
#include "../NodeBase.cpp"
#include "Instruction.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        class Block : public NodeBase
        {
        public:
            /// <summary>
            /// Instructions list
            /// </summary>
            list<Instruction*> instructions;

            Block() : NodeBase() { }

            Block(string str) : NodeBase(str) { }

            /// <summary>
            /// 
            /// </summary>
            /// <param name="tag"></param>
            /// <param name="blockName"></param>
            /// <returns></returns>
            Instruction* NewInstruction(string instructionName)
            {
                Instruction* i = new Instruction(instructionName);
                instructions.push_back(i);
                return i;
            }

            /// <summary>
            /// 
            /// </summary>
            /// <param name="instruction"></param>
            /// <returns></returns>
            Instruction* NewInstruction(Instruction* instruction)
            {
                instructions.push_back(instruction);
                return instruction;
            }

            void DOTNodesAdd(GraphvizDOT* dot)
            {
                for (auto& i : instructions)
                {
                    dot->Node(name, i->name);
                    i->DOTNodesAdd(dot);
                }
            }
        };
    }
}
