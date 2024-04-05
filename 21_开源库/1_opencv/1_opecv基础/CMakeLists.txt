cmake_minimum_required(VERSION 3.0)
project(image_from_img)
 
find_package(OpenCV REQUIRED)
add_executable(image_from_img.out 1_opencv_显示图片.cpp)
target_link_libraries(image_from_img.out ${OpenCV_LIBS})