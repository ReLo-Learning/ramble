file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(LexerLib STATIC ${Sources} ${Headers})