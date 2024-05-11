cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(VendMachine_NCS)

target_sources(app PRIVATE src/main.c ../VendMachine/src-gen/Statechart.c)
target_include_directories(app PRIVATE ../VendMachine/src-gen ../VendMachine/src)
