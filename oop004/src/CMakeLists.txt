set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(pdadd pdadd.cpp personalDiary.cpp personalDiary.h)
add_executable(pdlist pdlist.cpp personalDiary.cpp personalDiary.h)
add_executable(pdremove pdremove.cpp personalDiary.cpp personalDiary.h)
add_executable(pdshow pdshow.cpp personalDiary.cpp personalDiary.h)