#include "Phase1.h"
#include "ArrayList.h"
#include "rotate.h"
#include "Instruction.h"
#include "InstructionFactory.h"

void check_errors(struct ArrayList *unchecked, struct ArrayList *checked) 
{

    for (int i = 0; i < size(unchecked); i++)
    {
        struct Instruction ins = get(unchecked, i);
        uint32_t imm = ins.immediate;
        uint32_t shift = ins.shift_amount;
        
        uint32_t rightRotation = rotr32c (imm, shift);

        if (ins.instruction_id == add || ins.instruction_id == sub || ins.instruction_id == or
        || ins.instruction_id == lsl || ins.instruction_id == cmp || ins.instruction_id==b)
        {
          addLast(checked, ins);
        }

        else if (ins.instruction_id == addi || ins.instruction_id == subi || ins.instruction_id == ori ||ins.instruction_id==invalid)
        {
            if (imm == 0)
            {
                addLast(checked, ins);
            } 
            else if (imm > 0 && rightRotation%8==0) 
            {
                addLast(checked, ins);
            } 
            else if (imm < 0 && rightRotation%8==0)
            {
                if(ins.instruction_id == addi)
                {
                    ins.instruction_id = subi;
                    ins.immediate = -ins.immediate;
                }
                else if (ins.instruction_id == subi)
                {
                    ins.instruction_id = addi;
                    ins.immediate = -ins.immediate;
                }
    
                if (imm > 0 && rightRotation%8==0)
                {
                    addLast(checked, ins);
                }
            } 
            else
            {
                addLast(checked, INVALID());
            }
        }
    }    
    
}


/*
switch()
    {
        case (ins.instruction_id == add):
        break;
        case (ins.instruction_id == addi):
        break;
        case (ins.instruction_id == sub):
        break;
        case (ins.instruction_id == subi):
        break;
        case (ins.instruction_id == orr):
        break;
        case (ins.instruction_id == orri):
        break;
        case (ins.instruction_id == lsl):
        break;
        case (ins.instruction_id == cmp):
        break; 
    }
    */
