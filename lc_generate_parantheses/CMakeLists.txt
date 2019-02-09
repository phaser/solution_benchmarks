cmake_minimum_required(VERSION 3.12)
set (PNAME "lc_generate_parantheses")
project (${PNAME})

add_definitions("-O3")
add_executable(${PNAME} "${PNAME}.cpp")

