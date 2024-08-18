file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(Codegen STATIC ${Sources} ${Headers})