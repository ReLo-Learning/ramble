file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(ASTLib STATIC ${Sources} ${Headers})