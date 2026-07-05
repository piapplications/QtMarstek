#include <QtTest>

#include "TestUtils.h"
#include "MarstekPacketReader.h"

using namespace QtMarstek;

class TestMarstekPacketReader : public QObject {
      Q_OBJECT

   private slots:
      void constructor();
      void readUInt8();
      void readUInt16BE();
      void readUInt16LE();
      void readUInt32BE();
      void readUInt32LE();
      void readBytes();
      void seek();
      void skip();
      void reset();
      void endOfBuffer();
};

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::constructor() {
    QByteArray data;
    MarstekPacketReader reader(data);
    QVERIFY(reader.atEnd());
    QVERIFY(!reader.hasError());
    QCOMPARE(reader.position(), qsizetype(0));
    QCOMPARE(reader.size(), qsizetype(0));
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readUInt8() {
    QByteArray data;
    data.append(char(0x12));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt8(), quint8(0x12));
    QVERIFY(reader.atEnd());
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readUInt16BE() {
    QByteArray data;
    data.append(char(0x12));
    data.append(char(0x34));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt16BE(), quint16(0x1234));
    QVERIFY(reader.atEnd());
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readUInt16LE() {
    QByteArray data;
    data.append(char(0x34));
    data.append(char(0x12));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt16LE(), quint16(0x1234));
    QVERIFY(reader.atEnd());
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readUInt32BE() {
    QByteArray data;
    data.append(char(0x12));
    data.append(char(0x34));
    data.append(char(0x56));
    data.append(char(0x78));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt32BE(), quint32(0x12345678));
    QVERIFY(reader.atEnd());
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readUInt32LE() {
    QByteArray data;
    data.append(char(0x78));
    data.append(char(0x56));
    data.append(char(0x34));
    data.append(char(0x12));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt32LE(), quint32(0x12345678));
    QVERIFY(reader.atEnd());
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::readBytes() {
    QByteArray data("ABCDE");
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readBytes(3), QByteArray("ABC"));
    QCOMPARE(reader.position(), qsizetype(3));
    QCOMPARE(reader.remaining(), qsizetype(2));
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::seek() {
    QByteArray data("ABCDE");
    MarstekPacketReader reader(data);
    QVERIFY(reader.seek(2));
    QCOMPARE(reader.position(), qsizetype(2));
    QCOMPARE(reader.readUInt8(), quint8('C'));
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::skip() {
    QByteArray data("ABCDE");
    MarstekPacketReader reader(data);
    QVERIFY(reader.skip(3));
    QCOMPARE(reader.position(), qsizetype(3));
    QCOMPARE(reader.readUInt8(), quint8('D'));
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::reset() {
    QByteArray data;
    data.append(char(0x12));
    data.append(char(0x34));
    MarstekPacketReader reader(data);
    reader.readUInt8();
    QCOMPARE(reader.position(), qsizetype(1));
    reader.reset();
    QCOMPARE(reader.position(), qsizetype(0));
    QVERIFY(!reader.hasError());
    QCOMPARE(reader.readUInt16BE(), quint16(0x1234));
}

//-----------------------------------------------------------------------------

void TestMarstekPacketReader::endOfBuffer() {
    QByteArray data;
    data.append(char(0x12));
    MarstekPacketReader reader(data);
    QCOMPARE(reader.readUInt16BE(), quint16(0));
    QVERIFY(reader.hasError());
    QVERIFY(!reader.errorString().isEmpty());
}

//-----------------------------------------------------------------------------

QTEST_APPLESS_MAIN(TestMarstekPacketReader)

#include "TestMarstekPacketReader.moc"
