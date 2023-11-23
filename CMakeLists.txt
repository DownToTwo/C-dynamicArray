
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g3 -Wpedantic -fsanitize=address,leak,undefined -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum -Wconversion -Wunreachable-code -Wwrite-strings -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -pedantic -z nodelete -fanalyzer -Wfloat-equal -Wundef -fverbose-asm -std=c99 -Wpadded -finstrument-functions -ggdb3")
project(Vector)

add_executable(app main.c vector.c)
add_executable(test vectest.c vector.c)
