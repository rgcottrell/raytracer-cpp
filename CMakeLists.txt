cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(raytracer C CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        raytracer/Camera.h
        raytracer/CheckerTexture.h
        raytracer/ConstantTexture.h
        raytracer/Dielectric.h
        raytracer/HitRecord.h
        raytracer/Lambertian.h
        raytracer/Material.h
        raytracer/Math.h
        raytracer/Math.cpp
        raytracer/Metal.h
        raytracer/MovingSphere.h
        raytracer/Ray.h
        raytracer/ScatterRecord.h
        raytracer/Sphere.h
        raytracer/Surface.h
        raytracer/SurfaceGroup.h
        raytracer/Texture.h
        raytracer/Vector3.h
        raytracer/main.cpp
        )

add_executable(raytracer ${SOURCE_FILES})

if(MSVC)
    target_compile_options(raytracer PRIVATE /std:c++latest)
    set_target_properties(raytracer PROPERTIES COMPILE_DEFINITIONS "_USE_MATH_DEFINES=1")
endif()
