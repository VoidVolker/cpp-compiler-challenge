// Compiler.cpp: определяет точку входа для приложения.
//

#include "Compiler.h"
#include "lib/Test.cpp"

using namespace std;
using namespace Compiler;

void v1() 
{
    {
        using namespace Compiler::ModuleV1;
        Module* m = new Module("test module");
        Function* f = m->NewFunction("Test function 1");
        Block* b1 = f->entry->Successor("A", "Test block 1");
        Block* b2 = f->entry->Successor("B", "Test block 2");

        b1->Successor("true", "A block sc 1");
        b1->Successor("false", "B block sc 2");
        b2->Successor("true", "A block sc 3");

        auto s4 = b2->Successor("false", "B block sc 4");
        s4->Successor("", "Test block 2");

        cout << m->ToDOT() << endl;
    }
}

void v2()
{
    {
        using namespace Compiler::ModuleV2;
        using namespace Compiler::ModuleV2::Instructions;

        Module* m = new Module("Compiler");
        Function* f = m->NewFunction("main");
        Block* entry = f->entry;

        entry->NewInstruction(new Store(0x48, 0));
        entry->NewInstruction(new Store(0x65, 1));
        entry->NewInstruction(new Store(0x6C, 2));
        entry->NewInstruction(new Store(0x6C, 3));
        entry->NewInstruction(new Store(0x6F, 4));
        entry->NewInstruction(new Store(0x20, 5));
        entry->NewInstruction(new Store(0x57, 6));
        entry->NewInstruction(new Store(0x6F, 7));
        entry->NewInstruction(new Store(0x72, 8));
        entry->NewInstruction(new Store(0x6C, 9));
        entry->NewInstruction(new Store(0x64, 10));
        entry->NewInstruction(new Store(0x21, 11));

        cout << m->ToDOT() << endl;
    }
}

void line() {
    cout << string(50, '-') << endl << endl;
}


int main()
{
    v1();
    line();

    v2();
    line();

    new Test();

    system("pause");
    return 0;
}