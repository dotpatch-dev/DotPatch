set(IMGUI_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

set(IMGUI_SOURCES
	"imgui.cpp"
)
list(TRANSFORM IMGUI_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/imgui/")

add_library(imgui-static STATIC ${IMGUI_SOURCES})
target_include_directories(imgui-static PUBLIC ${IMGUI_INCLUDE_DIRS})