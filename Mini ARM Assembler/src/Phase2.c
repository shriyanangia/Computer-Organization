#include "Phase2.h"
#include "ArrayList.h"
#include "InstructionFactory.h"
#include "rotate.h"


void resolve_addresses(struct ArrayList *unresolved, uint32_t first_pc, struct ArrayList *resolved) 
{
    //first for loop
    //finding branches that occur before label
    for (int i = 0; i < size(unresolved); i++)
    {
        struct Instruction ins = get(unresolved, i);
        uint32_t imm = ins.immediate;
        char branchArr[46];
        if (ins.instruction_id == b)
        {
            branchArr[i] = ins.instruction_id;
        }

        //if instruction is not a branch instruction, it won't be changed
        else if (ins.instruction_id==invalid)
        {
            addLast(resolved,ins);
        }

        for (int j=0; i<size(unresolved); j++)
        {
            if (ins.branch_label == branchArr[j])
            {
                imm = imm+1;
                j = j+2;
            }
        }
    
    }

}

