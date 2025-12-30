//
// Created by andre on 29/12/2025.
//

#pragma once
#include "../common/types.h"

class ALU {
    public:
        struct Result {
            cvsim::word_t value;
            bool zero;              // Flag de zero
        };

        Result execute(cvsim::ALUOp op, cvsim::word_t src1, cvsim::word_t src2) {
            cvsim::word_t res = 0;

            switch (op) {
                case cvsim::ALUOp::ADD: res = src1 + src2; break;
                case cvsim::ALUOp::SUB: res = src1 - src2; break;
                case cvsim::ALUOp::AND: res = src1 & src2; break;
                case cvsim::ALUOp::OR:  res = src1 | src2; break;
                case cvsim::ALUOp::XOR: res = src1 ^ src2; break;
                case cvsim::ALUOp::SLL: res = src1 << (src2 & 0x1F); break;
                case cvsim::ALUOp::SRL: res = src1 >> (src2 & 0x1F); break;
                case cvsim::ALUOp::SRA: res = static_cast<int32_t>(src1) >> (src2 & 0x1F); break;
                case cvsim::ALUOp::SLT: res = (static_cast<int32_t>(src1) < static_cast<int32_t>(src2)) ? 1 : 0; break;
                case cvsim::ALUOp::SLTU: res = (src1 < src2) ? 1 : 0; break;
                default:
                    std::cerr << "[ALU] Erro: Operação ALU desconhecida!" << std::endl;
                    break;
            }

            return {res, res == 0};
        }
};
