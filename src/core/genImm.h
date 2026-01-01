//
// Created by andre on 01/01/2026.
//

#pragma once
#include "../common/types.h"
#include "../common/utils.h"

namespace cvsim {
    cvsim::word_t genImm(cvsim::DecodedInstr decoded, cvsim::InstrType type) {
        using namespace utils;
        switch (type) {
            case cvsim::InstrType::I_TYPE:
                return sign_extend(decoded.i_type.imm, 12);
            case cvsim::InstrType::S_TYPE:
                uint32_t imm = (decoded.s_type.imm11_5 << 5) | decoded.s_type.imm4_0;
            return sign_extend(imm, 12);
            case cvsim::InstrType::B_TYPE:
                uint32_t imm = (get_bit(decoded.b_type.imm12, 0) << 12) |
                               (decoded.b_type.imm4_1 << 1) |
                               (decoded.b_type.imm11_5 << 5);
            return sign_extend(imm, 13);
            case cvsim::InstrType::U_TYPE:
                return decoded.u_type.imm31_12 << 12;
            case cvsim::InstrType::J_TYPE:
                uint32_t imm = (get_bit(decoded.j_type.imm20, 0) << 20) |
                               (decoded.j_type.imm10_1 << 1) |
                               (decoded.j_type.imm11 << 11) |
                               (decoded.j_type.imm19_12 << 12);
            return sign_extend(imm, 21);
            default:
                return 0;
        }
    }
}
