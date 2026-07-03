# src/CMakeLists.txt

qt_add_library(QtMarstek STATIC
    DeviceInfo.cpp
    JsonRpcUtils.h
    JsonRpcUtils.cpp
    MarstekConstants.h
    MarstekDevice.h
    MarstekDevice.cpp
    MarstekMethods.h
    MarstekDiscovery.h
    MarstekProtocol.h
    MarstekPacket.h
    MarstekDiscovery.cpp
    MarstekDatagram.h
    MarstekDiscovery.h
    MarstekDiscoveryInfo.h
    MarstekProtocol.cpp
    MarstekPacket.cpp
    MarstekTransport.h
    MarstekTransport.cpp
    DeviceInfo.h
)

target_sources(QtMarstek
    PRIVATE

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS .
        FILES      
)

target_link_libraries(QtMarstek
    PUBLIC
        Qt6::Core
        Qt6::Network
)

target_compile_features(QtMarstek PUBLIC cxx_std_20)

target_include_directories(QtMarstek
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
