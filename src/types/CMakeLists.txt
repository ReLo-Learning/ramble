file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp *.h)

add_library(Types STATIC ${Sources} ${Headers})