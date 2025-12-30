//
// Created by andre on 29/12/2025.
//

#pragma once
#include "../common/types.h"
#include "regfile.h"
#include "alu.h"
#include "../memory/bus.h"
#include <array>
#include <iostream>

class CPU {
    private:
        RegFile regFile;
        ALU alu;
        Bus& bus;
        cvsim::word_t pc;

    // TODO: Adicionar funções auxiliares para fetch, decode, execute, memory e write-back

    public:
        CPU(Bus& system_bus) : bus(system_bus), pc(cvsim::RESET_VECTOR) {}

        void reset() {
            regFile.reset();
            pc = cvsim::RESET_VECTOR;
        }

        void step() {
            // TODO: Implementar o ciclo de busca, decodificação, execução, memória e escrita de volta
        }
};

