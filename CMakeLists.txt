cmake_minimum_required(VERSION 3.5)

project(testCmake LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets sql LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets sql LinguistTools REQUIRED)

set(TS_FILES testCmake_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
        res.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(testCmake
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(testCmake SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(testCmake WIN32
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

# Remove the console of gui program
# if(WIN32)
# 	if(MSVC)
# 		set_target_properties(${PROJECT_NAME} PROPERTIES
# 			WIN32_EXECUTABLE YES
# 			LINK_FLAGS "/ENTRY:mainCRTStartup"
# 		)
# 	elseif(CMAKE_COMPILER_IS_GNUCXX)
# 			# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
# 	else()
# 		message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
# 	endif(MSVC)
# elseif(APPLE)
# 	set_target_properties(${PROJECT_NAME} PROPERTIES
# 			MACOSX_BUNDLE YES
# 	)
# elseif(UNIX)
# 	# Nothing special required
# else()
# 	message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
# endif(WIN32)


target_link_libraries(testCmake PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(testCmake PRIVATE "${CMAKE_BINARY_DIR}/TestCmake_autogen/include_Debug")
