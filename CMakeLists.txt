cmake_minimum_required(VERSION 3.25)
project(tau_cs_hackathon C)

set(CMAKE_C_STANDARD 99)
add_executable(tau_cs_hackathon main.c)
target_link_libraries(tau_cs_hackathon ws2_32)