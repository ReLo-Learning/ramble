file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(Utils STATIC ${Sources} ${Headers})