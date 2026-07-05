#include <QtTest>
#include <QStringView>

#include "TestUtils.h"
#include "MarstekPacketReader.h"
#include "MarstekPacketWriter.h"

using namespace QtMarstek;

class TestMarstekPacketWriter : public QObject {
    Q_OBJECT

private slots:
    void constructor();
    void writeUInt8();
    void writeUInt16BE();
    void writeUInt16LE();
    void writeUInt32BE();
    void writeUInt32LE();
    void writeBytes();
    void writeString();
    void clear();
    void reserve();
    void roundTrip();
};

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::constructor() {
    MarstekPacketWriter writer;
    QVERIFY(writer.isEmpty());
    QCOMPARE(writer.size(), 0);
    QVERIFY(!writer.hasError());
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeUInt8() {
    MarstekPacketWriter writer;
    writer.writeUInt8(0x12);
    QCOMPARE(writer.size(), 1);
    QCOMPARE(writer.buffer(), fromHex("12"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeUInt16BE() {
    MarstekPacketWriter writer;
    writer.writeUInt16BE(0x1234);
    QCOMPARE(writer.size(), 2);
    QCOMPARE(writer.buffer(), fromHex("12 34"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeUInt16LE() {
    MarstekPacketWriter writer;
    writer.writeUInt16LE(0x1234);
    QCOMPARE(writer.size(), 2);
    QCOMPARE(writer.buffer(), fromHex("34 12"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeUInt32BE() {
    MarstekPacketWriter writer;
    writer.writeUInt32BE(0x12345678);
    QCOMPARE(writer.size(), 4);
    QCOMPARE(writer.buffer(), fromHex("12 34 56 78"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeUInt32LE() {
    MarstekPacketWriter writer;
    writer.writeUInt32LE(0x12345678);
    QCOMPARE(writer.size(), 4);
    QCOMPARE(writer.buffer(), fromHex("78 56 34 12"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeBytes() {
    MarstekPacketWriter writer;
    QByteArray data;
    data.append(char(0x11));
    data.append(char(0x22));
    data.append(char(0x33));
    writer.writeBytes(data);
    QCOMPARE(writer.buffer(), data);
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::writeString() {
    MarstekPacketWriter writer;
    writer.writeString("ABC");
    QCOMPARE(writer.buffer(), QByteArray("ABC"));
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::clear() {
    MarstekPacketWriter writer;
    writer.writeUInt32BE(0x12345678);
    QVERIFY(!writer.isEmpty());
    writer.clear();
    QVERIFY(writer.isEmpty());
    QCOMPARE(writer.size(), 0);
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::reserve() {
    MarstekPacketWriter writer;
    writer.reserve(256);
    QVERIFY(writer.isEmpty());
    writer.writeUInt8(0x12);
    QCOMPARE(writer.size(), 1);
}

//---------------------------------------------------------------------------

void TestMarstekPacketWriter::roundTrip() {
    MarstekPacketWriter writer;
    writer.writeUInt8(0x12);
    writer.writeUInt16BE(0x3456);
    writer.writeUInt32LE(0x12345678);
    writer.writeString("Qt");
    MarstekPacketReader reader(writer.buffer());
    QCOMPARE(reader.readUInt8(), quint8(0x12));
    QCOMPARE(reader.readUInt16BE(), quint16(0x3456));
    QCOMPARE(reader.readUInt32LE(), quint32(0x12345678));
    QCOMPARE(reader.readString(2), QStringLiteral("Qt"));
    QVERIFY(!reader.hasError());
    QVERIFY(reader.atEnd());
}

//---------------------------------------------------------------------------

QTEST_APPLESS_MAIN(TestMarstekPacketWriter)

#include "TestMarstekPacketWriter.moc"
