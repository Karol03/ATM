cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME ATM)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

set(HEADER
    ../Dispatcher.h
    ../Component.h
    ../Bank.h
    ../Message.h
	../MessagePort.h
	../MessageObserver.hpp
    ../ControlerDispatcher.hpp
    ../EmptyDispatcher.hpp
    ../ATM.hpp
    ../Logger.hpp
    ../StateIdle.hpp
    ../StateValidating.hpp
    ../StateProcessing.hpp
  )

set(SOURCE
    ../Bank.cpp
	../MessageObserver.cpp
	../EmptyDispatcher.cpp
	../ControlerDispatcher.cpp
	../StateIdle.cpp
	../StateValidating.cpp
	../StateProcessing.cpp
  )

add_executable(${PROJECT_NAME} ../main.cpp ${HEADER} ${SOURCE})

target_link_libraries(${PROJECT_NAME} pthread)
