#pragma once
#include <list>
#include "Function.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV1 {
        class Module : public NodeBase
        {
        public:
            /// <summary>
            /// Functions list
            /// </summary>
            list<Function*> functions;

            Module() : NodeBase() { }

            Module(string moduleName) : NodeBase(moduleName) { }

            /// <summary>
            /// Create new function and add it to current module
            /// </summary>
            /// <param name="functionName"></param>
            /// <returns></returns>
            Function* NewFunction(string functionName)
            {
                Function* f = new Function(functionName);
                functions.push_back(f);
                return f;
            }



            void DOTNodesAdd(GraphvizDOT* dot)
            {
                for (auto& function : functions)
                {
                    dot->Node(name, function->name);
                    function->DOTNodesAdd(dot);
                }
            }
        };
    }
}