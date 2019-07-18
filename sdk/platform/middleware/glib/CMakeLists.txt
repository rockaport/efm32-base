project(middleware-glib)

add_library(${PROJECT_NAME}
        dmd/display/dmd_display.c
#        dmd/ssd2119/dmd_ssd2119.c
#        dmd/ssd2119/dmdif_ssd2119_ebi16.c
#        dmd/ssd2119/dmdif_ssd2119_ebi.c
#        dmd/ssd2119/dmd_ssd2119_direct.c
#        dmd/ssd2119/dmdif_ssd2119_spi.c
#        dmd/ssd2119/dmd_ssd2119_16bit.c
#        dmd/etm043010edh6/dmd_etm043010edh6.c
        glib/glib_rectangle.c
        glib/glib_bitmap.c
        glib/glib_line.c
        glib/glib_font_number_16x20.c
        glib/glib_font_narrow_6x8.c
        glib/glib_circle.c
        glib/glib.c
        glib/glib_polygon.c
        glib/glib_font_normal_8x8.c
        glib/bmp.c
        glib/glib_string.c)

target_include_directories(${PROJECT_NAME} PUBLIC
        .
        dmd
        dmd/display
        glib)

target_link_libraries(${PROJECT_NAME} hardware device)