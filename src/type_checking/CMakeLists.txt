file(GLOB Source *.cpp)
file(GLOB Headers *.hpp)

add_library(TypeChecker STATIC ${Source} ${Headers})
