cmake_minimum_required(VERSION 3.21)
project(fetch_build_package_demo VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# 让依赖更安静、构建更快（可选）
set(FMT_DOC OFF CACHE BOOL "" FORCE)
set(FMT_TEST OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_executable(hello_demo src/main.cpp)
target_link_libraries(hello_demo PRIVATE fmt::fmt)
target_compile_features(hello_demo PRIVATE cxx_std_17)

# -------- 安装规则 --------
include(GNUInstallDirs)

install(TARGETS hello_demo
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# -------- 打包（CPack）--------
set(CPACK_PACKAGE_NAME "hello-demo")
set(CPACK_PACKAGE_VENDOR "demo")
set(CPACK_PACKAGE_CONTACT "you@example.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Demo: FetchContent + build + install + package")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

# 生成 .deb 和 .tar.gz（也可以只留一个）
set(CPACK_GENERATOR "DEB;TGZ")

# DEB 相关信息（最基本字段）
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "demo")

include(CPack)