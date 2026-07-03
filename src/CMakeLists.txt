qt_add_library(QtMarstek STATIC)

target_sources(QtMarstek PRIVATE
    MarstekClient.cpp
)

target_sources(QtMarstek PUBLIC
    FILE_SET HEADERS
    BASE_DIRS .
    FILES
        MarstekClient.h
)

target_link_libraries(QtMarstek
    PUBLIC
        Qt6::Core
        Qt6::Network
)
