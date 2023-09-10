file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(CodegenLib ${Sources} ${Headers})