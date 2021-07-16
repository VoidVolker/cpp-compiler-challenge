#pragma once
#include <list>
#include "../Instruction.cpp"

using namespace std;

namespace Compiler {
    namespace ModuleV2 {
        namespace Instructions {
            class Store : public Instruction {
            public:
                Store(unsigned int valueGlobalVar = 0, unsigned int addressGlobalVar = 0) : Instruction("Store")
                {
                    this->NewOperand("value", valueGlobalVar);
                    this->NewOperand("address", addressGlobalVar);
                }
            };
        }
    }
}
