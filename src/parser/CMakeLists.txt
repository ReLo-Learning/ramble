file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(ParserLib STATIC ${Sources} ${Headers})