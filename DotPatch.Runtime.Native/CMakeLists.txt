find_package(unofficial-nethost CONFIG REQUIRED)

add_library(DotPatch.Runtime.Native SHARED
	source/runtime/init.cc
	source/runtime/host.cc
	source/runtime/create_host.cc

	source/debug/panic.cc
	source/debug/console.cc
	source/debug/logging.cc

	source/dll_main.cc
)
target_include_directories(DotPatch.Runtime.Native PUBLIC include)
target_link_libraries(DotPatch.Runtime.Native PRIVATE unofficial::nethost::nethost)


add_executable(DotPatch.Runtime.Native.Test
	source/exe_main.cc
)
target_link_libraries(DotPatch.Runtime.Native.Test DotPatch.Runtime.Native)