cmake_minimum_required(VERSION 3.30)
project(Caitsidhe_V)

set(CMAKE_CXX_STANDARD 20)

add_executable(Caitsidhe_V src/main.cpp
        src/common/utils.h
        src/common/types.h
        src/core/alu.h
        src/core/control.h
        src/core/cpu.h
        src/core/pipeline_regs.h
        src/core/regfile.h
        src/memory/bus.h
        src/memory/ram.h
        src/peripherals/uart.h
        src/core/genImm.h)
