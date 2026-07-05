qt_add_library(QtMarstek STATIC
    DeviceInfo.cpp
    JsonRpcUtils.cpp
    MarstekDevice.cpp
    MarstekDiscovery.cpp
    MarstekPacket.cpp
    MarstekPacketReader.cpp
    MarstekPacketWriter.cpp
    MarstekProtocol.cpp
    MarstekTransport.cpp
)

target_link_libraries(QtMarstek
    PUBLIC
        Qt6::Core
        Qt6::Network
)

target_compile_features(QtMarstek
    PUBLIC
        cxx_std_20
)

target_include_directories(QtMarstek
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
