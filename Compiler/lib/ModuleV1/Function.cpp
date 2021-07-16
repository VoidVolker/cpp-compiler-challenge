#pragma once
#include <list>
#include "Block.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV1 {
        class Function : public NodeBase
        {
        public:
            inline static string default_entryName = "Entry";
            /// <summary>
            /// Entry block
            /// </summary>

            Block* entry;
            ///// <summary>
            ///// Other blocks list
            ///// </summary>
            //list<Block*> blocks;

            Function() : NodeBase() {
                entry = new Block(default_entryName);
            }

            Function(string functionName, string entryName = default_entryName) : NodeBase(functionName)
            {
                entry = new Block(entryName);
            }

            ///// <summary>
            ///// Create new block and add it to current function
            ///// </summary>
            ///// <param name="blockName"></param>
            ///// <returns></returns>
            //Block* NewBlock(string blockName)
            //{
            //    Block *b = new Block(blockName);
            //    blocks.push_back(b);
            //    return b;
            //}

            void DOTNodesAdd(GraphvizDOT* dot)
            {
                // Nodes from entry point
                dot->Node(name, entry->name);
                entry->DOTNodesAdd(dot);

                // All other nodes
                //for (auto& block : blocks)
                //{
                //    dot->Node(name, block->name);
                //    block->DOTNodesAdd(dot);
                //}
            }
        };
    }
}