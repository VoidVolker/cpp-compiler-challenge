#pragma once
#include <list>
#include "../Instruction.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        namespace Instructions {
            class Add : public Instruction {
            public:

                Add(string arg1, string arg2, string arg3) : Instruction("Add")
                {
                    this->NewOperand(arg1);
                    this->NewOperand(arg2);
                    this->NewOperand(arg3);
                }

                Add(
                    string arg1,
                    unsigned int arg1var,
                    string arg2,
                    unsigned int arg2var,
                    string arg3,
                    unsigned int arg3var
                ) : Instruction("Add")
                {
                    this->NewOperand(arg1, arg1var);
                    this->NewOperand(arg2, arg2var);
                    this->NewOperand(arg3, arg3var);
                }

                Add(list<string> arguments) : Instruction("Add")
                {
                    int len = arguments.size();
                    if (arguments.size() < 3) {
                        throw invalid_argument("Invalid arguments count. Expected: 3>=; Got: " + to_string(len));
                    }
                    for (auto& a : arguments)
                    {
                        this->NewOperand(a);
                    }
                }

                Add(unordered_map<string, unsigned int> argumentsAndVars) : Instruction("Add")
                {
                    int len = argumentsAndVars.size();
                    if (len < 3) {
                        throw invalid_argument("Invalid arguments count. Expected: 3>=; Got: " + to_string(len));
                    }
                    for (auto& [a, v] : argumentsAndVars)
                    {
                        this->NewOperand(a, v);
                    }
                }
            };
        }
    }
}
