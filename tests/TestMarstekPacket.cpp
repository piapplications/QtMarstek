#include <QtTest>

#include "TestUtils.h"
#include "MarstekPacket.h"

class TestMarstekPacket : public QObject {
    Q_OBJECT

private slots:
    void defaultConstructor();
    void append();
    void clear();
};

void TestMarstekPacket::defaultConstructor() {
    MarstekPacket packet;

    QVERIFY(packet.isEmpty());
    QCOMPARE(packet.size(), 0);
}

void TestMarstekPacket::append() {
    MarstekPacket packet;
    packet.append(quint8(0x12));
    packet.append(quint16(0x3456));
    packet.append(quint32(0x789ABCDE));

    QCOMPARE(packet.size(), 7);
    QCOMPARE(packet.at(0), quint8(0x12));
    QCOMPARE(packet.readUInt16BE(1), quint16(0x3456));
    QCOMPARE(packet.readUInt32BE(3), quint32(0x789ABCDE));
}

void TestMarstekPacket::clear() {
    MarstekPacket packet;
    packet.append(quint8(1));
    QVERIFY(!packet.isEmpty());
    packet.clear();
    QVERIFY(packet.isEmpty());
}

QTEST_APPLESS_MAIN(TestMarstekPacket)

#include "TestMarstekPacket.moc"
