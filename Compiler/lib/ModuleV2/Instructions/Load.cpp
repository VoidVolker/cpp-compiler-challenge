#pragma once
#include <list>
#include "../Instruction.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        namespace Instructions {
            class Load : public Instruction {
            public:
                Load(unsigned int globalVar = 0) : Instruction("Load")
                {
                    this->NewOperand("address", globalVar);
                }
            };

        }
    }
}
