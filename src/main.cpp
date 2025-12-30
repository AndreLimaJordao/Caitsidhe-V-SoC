#include <iostream>
#include "common/types.h"
#include "common/utils.h"
#include "core/alu.h"
#include "core/regfile.h"
#include "memory/ram.h"
#include "memory/bus.h"

int main() {
    cvsim::word_t a = 10;
    cvsim::word_t b = 20;
    ALU alu;
    RegFile regFile;
    RAM ram(cvsim::MEM_SIZE);
    Bus bus(ram);
    regFile.write(1, a); // Escreve 10 em x1
    regFile.write(2, b); // Escreve 20 em x2
    ALU::Result result = alu.execute(cvsim::ALUOp::ADD, regFile.read(1), regFile.read(2));
    std::cout << "Resultado da ALU (ADD): " << result.value << std::endl; // Deve imprimir 30
    regFile.write(3, result.value); // Escreve o resultado em x3
    regFile.dump(); // Mostra o estado dos registradores
    return 0;
}