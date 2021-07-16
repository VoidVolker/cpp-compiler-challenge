#pragma once
#include <list>
#include <unordered_map>
#include "../NodeBase.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV1 {
        class Block : public NodeBase
        {
        public:
            /// <summary>
            /// Tags and successors blocks map
            /// </summary>
            unordered_map<string, Block*> successors;

            Block() : NodeBase() { }

            Block(string str) : NodeBase(str) { }

            /// <summary>
            /// Create new successor block and add it to current block
            /// </summary>
            /// <param name="tag"></param>
            /// <param name="blockName"></param>
            /// <returns></returns>
            Block* Successor(string tag, string blockName)
            {
                Block* b = new Block(blockName);
                successors[tag] = b;
                return b;
            }

            void DOTNodesAdd(GraphvizDOT* dot)
            {
                for (auto& [tag, block] : successors)
                {
                    dot->Node(name, block->name, tag);
                    block->DOTNodesAdd(dot);
                }
            }

        };
    }
}
