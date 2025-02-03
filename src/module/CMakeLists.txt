file(GLOB Source *.hpp)
file(GLOB Headers *.cpp)

add_library(Module STATIC ${Source} ${Headers})