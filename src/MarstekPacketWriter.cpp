#include "MarstekPacketWriter.h"

#include <QtEndian>

namespace QtMarstek {

    bool MarstekPacketWriter::hasError() const {
        return _error;
    }

    QString MarstekPacketWriter::errorString() const {
        return _errorString;
    }

    qsizetype MarstekPacketWriter::size() const {
        return _buffer.size();
    }

    bool MarstekPacketWriter::isEmpty() const {
        return _buffer.isEmpty();
    }

    const QByteArray &MarstekPacketWriter::buffer() const {
        return _buffer;
    }

    void MarstekPacketWriter::clear() {
        _buffer.clear();
        _error = false;
        _errorString.clear();
    }

    void MarstekPacketWriter::reserve(qsizetype size) {
        _buffer.reserve(size);
    }

    void MarstekPacketWriter::writeUInt8(quint8 value) {
        _buffer.append(static_cast<char>(value));
    }

    void MarstekPacketWriter::writeInt8(qint8 value) {
        _buffer.append(static_cast<char>(value));
    }

    void MarstekPacketWriter::writeUInt16BE(quint16 value) {
        const quint16 be = qToBigEndian(value);
        _buffer.append(reinterpret_cast<const char*>(&be), sizeof(be));
    }

    void MarstekPacketWriter::writeUInt16LE(quint16 value) {
        const quint16 le = qToLittleEndian(value);
        _buffer.append(reinterpret_cast<const char*>(&le), sizeof(le));
    }

    void MarstekPacketWriter::writeInt16BE(qint16 value) {
        writeUInt16BE(static_cast<quint16>(value));
    }

    void MarstekPacketWriter::writeInt16LE(qint16 value) {
        writeUInt16LE(static_cast<quint16>(value));
    }

    void MarstekPacketWriter::writeUInt32BE(quint32 value) {
        const quint32 be = qToBigEndian(value);

        _buffer.append(reinterpret_cast<const char*>(&be),
                       sizeof(be));
    }

    void MarstekPacketWriter::writeUInt32LE(quint32 value) {
        const quint32 le = qToLittleEndian(value);
        _buffer.append(reinterpret_cast<const char*>(&le), sizeof(le));
    }

    void MarstekPacketWriter::writeInt32BE(qint32 value) {
        writeUInt32BE(static_cast<quint32>(value));
    }

    void MarstekPacketWriter::writeInt32LE(qint32 value) {
        writeUInt32LE(static_cast<quint32>(value));
    }

    void MarstekPacketWriter::writeUInt64BE(quint64 value) {
        const quint64 be = qToBigEndian(value);
        _buffer.append(reinterpret_cast<const char*>(&be), sizeof(be));
    }

    void MarstekPacketWriter::writeUInt64LE(quint64 value) {
        const quint64 le = qToLittleEndian(value);
        _buffer.append(reinterpret_cast<const char*>(&le), sizeof(le));
    }

    void MarstekPacketWriter::writeBytes(QByteArrayView data) {
        _buffer.append(data.data(), data.size());
    }

    void MarstekPacketWriter::writeString(const QString &value, QStringConverter::Encoding encoding) {
        QStringEncoder encoder(encoding);
        const QByteArray encoded = encoder.encode(value);
        writeBytes(encoded);
    }

} // namespace QtMarstek