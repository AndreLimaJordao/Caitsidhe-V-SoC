//
// Created by andre on 29/12/2025.
//

#pragma once
#include "../common/types.h"
#include <array>
#include <cstdio>
#include <iostream>
#include <iomanip>

class RegFile {
    private:
        std::array<cvsim::word_t, 32> regs;

        const std::array<std::string, 32> abi_names = {
            "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
            "s0/fp", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
            "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
            "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
        };

    public:
        RegFile() {
            regs.fill(0);
        }

        cvsim::word_t read(cvsim::reg_addr_t addr) const {
            if (addr >= 32) {
                std::cerr << "[RF] Warning: Invalid address (Masking applied): " << static_cast<int>(addr) << std::endl;
            }
            cvsim::reg_addr_t bound_addr = addr & 0x1F; // Garante que o endereço está entre 0 e 31
            if (bound_addr == 0) return 0; // Registrador x0 é sempre zero
            return regs[bound_addr];
        }

        void write(cvsim::reg_addr_t addr, cvsim::word_t value) {
            if (addr >= 32) {
                std::cerr << "[RF] Warning: Invalid address (Masking applied): " << static_cast<int>(addr) << std::endl;
            }
            if (addr == 0) {
                std::cerr << "[RF] Warning: Attempt to write to x0 ignored." << std::endl;
                return;
            }
            cvsim::reg_addr_t bound_addr = addr & 0x1F; // Garante que o endereço está entre 0 e 31
            if (bound_addr == 0) return; // Registrador x0 é sempre zero
            regs[bound_addr] = value;
        }

        void reset() {
            regs.fill(0);
        }

        void dump() const {
            std::cout << "\n+==================================== Register File State ====================================+" << std::endl;
            std::cout << std::hex << std::setfill('0');

            for (int i = 0; i < 32; i += 4) {
                std::cout << "|";
                for (int j = 0; j < 4; j++) {
                    int r = i + j;
                    std::cout << "x" << std::dec << std::setw(2) << std::right << r
                              << "(" << std::setfill(' ') << std::setw(5) << abi_names[r] << "): "
                              << "0x" << std::setfill('0') << std::hex << std::setw(8) << std::right << regs[r] << "  ";
                }
                std::cout << std::endl;
            }
            std::cout << "+=============================================================================================+" << std::dec << std::endl;
        }
};
