file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(ErrorLib STATIC ${Sources} ${Headers})