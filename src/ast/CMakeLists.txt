file(GLOB Sources *.cpp ./statements/*.cpp ./expressions/*.cpp)
file(GLOB Headers *.hpp *.h ./statements/*.hpp ./expressions/*.hpp)

add_library(ASTLib STATIC ${Sources} ${Headers})