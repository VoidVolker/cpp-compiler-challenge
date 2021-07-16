#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
#include "ModuleV1/Module.cpp"

using namespace std;

namespace Compiler {
    class Test
    {
    private:
        int groupNameLength = 0;
        int counter = 0;
        int counterFails = 0;

        void GroupStart(string name) 
        {
            cout << "#------ " << name << " ------#" << endl;
            groupNameLength = name.length();
        }

        void GroupEnd() 
        {
            cout << "#-------" << string(groupNameLength, '-') << "-------#\n" << endl;
        }

        void Result() 
        {
            cout << "#------ Testing complited. Successes, fails and total: " << counter - counterFails << " + " << counterFails << " = " << counter << " ------#\n" << endl;
        }

    public:
        Test() 
        {
            ModuleTest();
            FunctionTest();
            BlockTest();
            Result();
        }

        void ModuleTest() 
        {
            GroupStart("Module");

            string moduleName = "Fruits";
            string functionName = "Orange";
            ModuleV1::Module* m1 = new ModuleV1::Module();
            ModuleV1::Module* m2 = new ModuleV1::Module(moduleName);

            assert(
                m1->name.size() == 0,
                "Can be created with defaults",
                "Wrong name. Expected: ''; got: '" + m1->name + "'"
            );

            assert(
                m2->name == moduleName,
                "Can be created with name",
                "Wrong name. Expected: '" + moduleName + "'; got: '" + m2->name + "'"
            );

            int count1 = m1->functions.size();
            ModuleV1::Function* f1 = m1->NewFunction(functionName);
            int count2 = m1->functions.size();
            ModuleV1::Function* f2 = m1->functions.back();

            assert(
                count1 + 1 == count2,
                "Function can be attached to module",
                "Wrong functions count. Expected: '" + to_string(count1 + 1) + "'; got: '" + to_string(count2) + "'"
            );

            assert(
                f2 == f1,
                "Function attached to module is same as created early",
                "Wrong name. Expected: '" + f1->name + "'; got: '" + f2->name + "'"
            );

            delete m1;
            delete m2;
            GroupEnd();
        }

        void FunctionTest()
        {
            GroupStart("Function");

            string functionName = "Mandarin";
            ModuleV1::Function* f1 = new ModuleV1::Function();
            ModuleV1::Function* f2 = new ModuleV1::Function(functionName);

            assert(
                f1->name.length() == 0,
                "Can be created with defaults",
                "Wrong name. Expected: ''; got: '" + f1->name + "'"
            );

            assert(
                f2->name == functionName,
                "Can be created with name",
                "Wrong name. Expected: '" + functionName + "'; got: '" + f2->name + "'"
            );

            // 1. It has a one and only one entry point.
            // Doesn't make sense for case, when function has only one field for entry point
            string t1 = typeid(f1->entry).name();
            string t2 = typeid(ModuleV1::Block*).name();
            assert(
                typeid(f1->entry) == typeid(ModuleV1::Block*),
                "Has only one entry point",
                "Wrong entry block type or block isn't created. Expected: '" + t2 + "'; got: '" + t1 + "'"
            );

            // 2. Each basic block is reachable from the entry point by traversing the links from a basic block to its successors.
            // Doesn't make sense in tree structure
            assert(
                f1->entry->name == ModuleV1::Function::default_entryName,
                "Entry block has default name",
                "Wrong entry block name. Expected: '" + ModuleV1::Function::default_entryName + "'; got: '" + f1->entry->name + "'"
            );

            delete f1;
            delete f2;
            GroupEnd();
        }

        void BlockTest()
        {
            GroupStart("Block");

            string blockName = "Vegetables";
            string sName1 = "Cabbage";
            string sName2 = "Potato";
            string tag1 = "One";
            string tag2 = "Two";
            ModuleV1::Block* b1 = new ModuleV1::Block(blockName);

            int count1 = b1->successors.size();
            ModuleV1::Block* s1 = b1->Successor(tag1, sName1);
            int count2 = b1->successors.size();

            assert(
                count1 + 1 == count2,
                "Able to add successor",
                "Wrong entry block name. Expected: '" + to_string(count1 + 1) + "'; got: '" + to_string(count2) + "'"
            );
                        
            assert(
                s1 == b1->successors[tag1],
                "Block attached to successors is same as created early",
                "Wrong entry block name. Expected: '" + sName1 + "'; got: '" + s1->name + "'"
            );

            // 3. Each basic block has, at most, one successor per tag.
            // Doesn't make sense in map structure
            ModuleV1::Block* s2 = b1->Successor(tag1, sName2);
            assert(
                b1->successors[tag1]->name == sName2,
                "Able to add only one successor per tag or adding new successor to existing tag overwrites it",
                "Wrong entry block name. Expected: '" + sName2 + "'; got: '" + b1->successors[tag1]->name + "'"
            );
            
            GroupEnd();
        }

        void assert(bool flag, string testCase, string details = "")
        {
            counter++;
            if (flag) {
                cout << "|-> Ok: <" << testCase << ">" << endl;
            }
            else
            {
                counterFails++;
                cout << "|-> Fail: <" << testCase << ">\n    " << details << endl;
            }
        }
    };
}