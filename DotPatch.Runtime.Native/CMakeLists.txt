find_package(unofficial-nethost CONFIG REQUIRED)

add_library(DotPatch.Runtime.Native SHARED
	source/runtime/panic.cc
	source/runtime/init.cc

	source/host/global.cc
	source/host/create_host.cc
)
target_include_directories(DotPatch.Runtime.Native PUBLIC include)
target_link_libraries(DotPatch.Runtime.Native PRIVATE unofficial::nethost::nethost)


add_executable(DotPatch.Runtime.Native.Test
	source/exe_main.cc
)
target_link_libraries(DotPatch.Runtime.Native.Test DotPatch.Runtime.Native)