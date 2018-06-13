cmake_minimum_required(VERSION 3.11)

PROJECT(game_1)
INCLUDE_DIRECTORIES(
	"/usr/include/irrlicht"
	${PROJECT_SOURCEC_DIR}/include
	)

FILE(GLOB SRCS src/*.cpp)
FILE(GLOB HDRS include/*.h)

ADD_EXECUTABLE(game_1
	${SRCS}
	${HDRS}
	)

TARGET_LINK_LIBRARIES(game_1
	"/usr/lib/libIrrlicht.so"
	)


