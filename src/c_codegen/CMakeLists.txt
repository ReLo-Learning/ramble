file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp)

add_library(C_Codegen ${Sources} ${Headers})