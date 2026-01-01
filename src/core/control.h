//
// Created by andre on 29/12/2025.
//

#pragma once
#include <iostream>

#include "../common/types.h"

namespace control {
    class ControlUnit {
        public:
            static cvsim::ControlSignals getSignals(cvsim::Opcode opcode) {
                cvsim::ControlSignals signals = {};
                switch (opcode) {
                    case cvsim::Opcode::R_TYPE:
                        signals = {true, false, false, false, false, false, true, false, cvsim::InstrType::R_TYPE};
                        break;
                    case cvsim::Opcode::I_TYPE:
                        signals = {true, false, false, false, false, true, false, false, cvsim::InstrType::I_TYPE};
                        break;
                    case cvsim::Opcode::LOAD:
                        signals = {true, true, true, false, false, true, false, false, cvsim::InstrType::I_TYPE};
                        break;
                    case cvsim::Opcode::STORE:
                        signals = {false, false, false, true, false, true, false, false, cvsim::InstrType::S_TYPE};
                        break;
                    case cvsim::Opcode::BRANCH:
                        signals = {false, false, false, false, true, false, false, true, cvsim::InstrType::B_TYPE};
                        break;
                    case cvsim::Opcode::LUI:
                        signals = {true, false, false, false, false, true, false, false, cvsim::InstrType::U_TYPE};
                        break;
                    case cvsim::Opcode::AUIPC:
                        signals = {true, false, false, false, false, true, false, false, cvsim::InstrType::U_TYPE};
                        break;
                    case cvsim::Opcode::JAL:
                        signals = {true, false, false, false, true, true, false, false, cvsim::InstrType::J_TYPE};
                        break;
                    case cvsim::Opcode::JALR:
                        signals = {true, false, false, false, true, true, false, false, cvsim::InstrType::I_TYPE};
                        break;
                    default:
                        std::cerr << "[ControlUnit] Warning: Unknown opcode! Opcode: " << std::hex << static_cast<int>(opcode) << std::dec << std::endl;
                        break;
                }
                return signals;
            }
    };
}