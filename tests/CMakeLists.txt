#
# QtMarstek - Unit tests
#

find_package(Qt6 REQUIRED COMPONENTS Test)

#
# --------------------------------------------------------------------
# TestMarstekPacket
# --------------------------------------------------------------------
#

qt_add_executable(TestMarstekPacket
    TestMarstekPacket.cpp
)

target_link_libraries(TestMarstekPacket
    PRIVATE
        QtMarstek
        Qt6::Core
        Qt6::Network
        Qt6::Test
)

add_test(
    NAME TestMarstekPacket
    COMMAND TestMarstekPacket
)

#
# --------------------------------------------------------------------
# TestMarstekPacketReader
# --------------------------------------------------------------------
#

qt_add_executable(TestMarstekPacketReader
    TestMarstekPacketReader.cpp
)

target_link_libraries(TestMarstekPacketReader
    PRIVATE
        QtMarstek
        Qt6::Core
        Qt6::Network
        Qt6::Test
)

add_test(
    NAME TestMarstekPacketReader
    COMMAND TestMarstekPacketReader
)

#
# --------------------------------------------------------------------
# TestMarstekPacketWriter
# --------------------------------------------------------------------
#

qt_add_executable(TestMarstekPacketWriter
    TestMarstekPacketWriter.cpp
)

target_link_libraries(TestMarstekPacketWriter
    PRIVATE
        QtMarstek
        Qt6::Core
        Qt6::Network
        Qt6::Test
)

add_test(
    NAME TestMarstekPacketWriter
    COMMAND TestMarstekPacketWriter
)

#
# --------------------------------------------------------------------
# TestMarstekProtocol
# --------------------------------------------------------------------
#

qt_add_executable(TestMarstekProtocol
    TestMarstekProtocol.cpp
)

target_link_libraries(TestMarstekProtocol
    PRIVATE
        QtMarstek
        Qt6::Core
        Qt6::Network
        Qt6::Test
)

add_test(
    NAME TestMarstekProtocol
    COMMAND TestMarstekProtocol
)

