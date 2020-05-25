cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 11)

# Project Name
Project(generator)
add_executable(${PROJECT_NAME} src/Generator/generator.cpp src/include/Ponto.h)


# Project Name
PROJECT(engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${PROJECT_NAME} src/Engine/engine.cpp src/Engine/tinyxml2.cpp src/Engine/Cor.cpp src/Engine/Escala.cpp src/Engine/Translacao.cpp src/Engine/CatmullRomCurve.cpp src/Engine/Rotacao.cpp src/Engine/Grupo.cpp)

include_directories(headers)
find_package(OpenGL REQUIRED)
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
include_directories(${OpenGL_INCLUDE_DIRS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

	message(STATUS "Toolkits_DIR set to: " ${TOOLKITS_FOLDER})
	set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")
	
	if (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
		message(ERROR ": GLUT not found")
	endif (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")	
	
	if (NOT EXISTS "${TOOLKITS_FOLDER}/glew/GL/glew.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glew/glew32.lib")
		message(ERROR ": GLEW not found")
	endif (NOT EXISTS "${TOOLKITS_FOLDER}/glew/GL/glew.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glew/glew32.lib")	
	
	include_directories(${TOOLKITS_FOLDER}/glut ${TOOLKITS_FOLDER}/glew)
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} 
										  ${TOOLKITS_FOLDER}/glut/glut32.lib 
										  ${TOOLKITS_FOLDER}/glew/glew32.lib )
	
	if (EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" AND EXISTS "${TOOLKITS_FOLDER}/glew/glew32.dll")
		file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
		file(COPY ${TOOLKITS_FOLDER}/glew/glew32.dll DESTINATION ${CMAKE_BINARY_DIR})
	endif(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" AND EXISTS "${TOOLKITS_FOLDER}/glew/glew32.dll")	
	
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	
	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/sphere.3d DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/torus.3d DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/teapot.3d DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${CMAKE_SOURCE_DIR}/config.xml DESTINATION ${CMAKE_BINARY_DIR})
	file(COPY ${CMAKE_SOURCE_DIR}/files/input_files/teapot.patch DESTINATION ${CMAKE_BINARY_DIR})
	
else (WIN32) #Linux and Mac

	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIR})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})
	
	if (NOT APPLE)
		find_package(GLEW REQUIRED)
		include_directories(${GLEW_INCLUDE_DIRS})
		link_libraries(${GLEW_LIBRARIES})
	endif(NOT APPLE)
	
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
	if(NOT GLUT_FOUND)
	   message(ERROR ": GLUT not found!")
	endif(NOT GLUT_FOUND)

	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/sphere.3d DESTINATION ${CMAKE_BINARY_DIR}/Debug)
	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/torus.3d DESTINATION ${CMAKE_BINARY_DIR}/Debug)
	file(COPY ${CMAKE_SOURCE_DIR}/files/3d/teapot.3d DESTINATION ${CMAKE_BINARY_DIR}/Debug)
	file(COPY ${CMAKE_SOURCE_DIR}/config.xml DESTINATION ${CMAKE_BINARY_DIR}/Debug)
	file(COPY ${CMAKE_SOURCE_DIR}/files/input_files/teapot.patch DESTINATION ${CMAKE_BINARY_DIR}/Debug)
	
endif(WIN32)