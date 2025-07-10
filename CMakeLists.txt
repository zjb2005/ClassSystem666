cmake_minimum_required(VERSION 3.16)

project(classsystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)
#zjb
find_package(Qt6 COMPONENTS Core Gui PrintSupport REQUIRED)  # Qt6
# 查找 Qt 库
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia)
#zjb end
set(TS_FILES classsystem_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        widget.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(classsystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        form.h form.cpp form.ui
        classset.h classset.cpp classset.ui
        student.h
        student.cpp
        classnumbersetform.h classnumbersetform.cpp classnumbersetform.ui
        classdata.h classdata.cpp
        startclassform.h startclassform.cpp startclassform.ui
        rec.qrc
        classes.h
        printerclassesresult.h printerclassesresult.cpp printerclassesresult.ui
        printAPI.h
        printAPI.cpp


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET classsystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(classsystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(classsystem
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(classsystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.classsystem)
endif()
set_target_properties(classsystem PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS classsystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(classsystem)
endif()

# zjb made
add_subdirectory(QXlsx)
target_link_libraries(classsystem PRIVATE QXlsx::QXlsx)
target_link_libraries(classsystem PRIVATE Qt6::PrintSupport)
# 链接 Qt 库
target_link_libraries(classsystem PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
)

# 设置目标属性
set_target_properties(classsystem PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# 自动处理 moc、uic 和 rcc
qt_finalize_executable(classsystem)
