set(SOURCE_FILES
        Camera.h
        Dielectric.h
        HitRecord.h
        Lambertian.h
        Material.h
        Math.h
        Math.cpp
        Metal.h
        Ray.h
        ScatterRecord.h
        Sphere.h
        Surface.h
        SurfaceGroup.h
        Vector3.h
        main.cpp
        )

add_executable(raytracer ${SOURCE_FILES})
if(MSVC)
    target_compile_options(raytracer PRIVATE /std:c++latest)
    set_target_properties(raytracer PROPERTIES COMPILE_DEFINITIONS "_USE_MATH_DEFINES=1")
endif()