file(GLOB Sources *.cpp ./statements/*.cpp)
file(GLOB Headers *.hpp *.h)

add_library(ParserLib STATIC ${Sources} ${Headers})