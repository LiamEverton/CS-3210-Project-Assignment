cmake_minimum_required(VERSION 3.13)
project(CS_3210_Project_Assignment)

set(CMAKE_CXX_STANDARD 17)

set(Boost_INCLUDE_DIR /usr/include/)
set(Boost_LIBRARY_DIR /usr/lib/)

include_directories(src)

find_package(Boost 1.6.5 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(CS_3210_Project_Assignment
        src/simulation/ecosystem/entity/comp/Position.cpp
        src/simulation/ecosystem/entity/comp/Position.h
        src/simulation/ecosystem/entity/type/EntityType.h
        src/simulation/ecosystem/entity/Entity.h
        src/simulation/ecosystem/entity/Entity.cpp
        src/simulation/ecosystem/entity/impl/organism/Organism.cpp
        src/simulation/ecosystem/entity/impl/organism/Organism.h
        src/simulation/ecosystem/entity/impl/organism/impl/animal/Animal.cpp
        src/simulation/ecosystem/entity/impl/organism/impl/animal/Animal.h
        src/simulation/ecosystem/entity/impl/organism/impl/plant/Plant.cpp
        src/simulation/ecosystem/entity/impl/organism/impl/plant/Plant.h
        src/simulation/ecosystem/entity/impl/organism/factory/OrganismFactory.cpp
        src/simulation/ecosystem/entity/impl/organism/factory/OrganismFactory.h
        src/simulation/ecosystem/iteration/Iteration.cpp
        src/simulation/ecosystem/iteration/Iteration.h
        src/simulation/ecosystem/EcoSystem.cpp
        src/simulation/ecosystem/EcoSystem.h
        src/input/InputProcessor.cpp
        src/input/InputProcessor.h
        src/simulation/Simulation.cpp
        src/simulation/Simulation.h
        main.cpp)

target_link_libraries(CS_3210_Project_Assignment ${Boost_LIBRARIES})