#include "MarstekPacketReader.h"

#include <QtEndian>

namespace QtMarstek {

MarstekPacketReader::MarstekPacketReader(QByteArrayView buffer) {
    _buffer = buffer;
}

bool MarstekPacketReader::atEnd() const {
    return _position >= _buffer.size();
}

bool MarstekPacketReader::hasError() const {
    return _error;
}

QString MarstekPacketReader::errorString() const {
    return _errorString;
}

qsizetype MarstekPacketReader::size() const {
    return _buffer.size();
}

qsizetype MarstekPacketReader::position() const {
    return _position;
}

qsizetype MarstekPacketReader::remaining() const {
    return _buffer.size() - _position;
}

QByteArrayView MarstekPacketReader::buffer() const {
    return _buffer;
}

bool MarstekPacketReader::seek(qsizetype position) {
    if (position < 0 || position > _buffer.size()) {
        _error = true;
        _errorString = QStringLiteral("Invalid position.");
        return false;
    }
    _position = position;
    return true;
}

bool MarstekPacketReader::skip(qsizetype length) {
    return seek(_position + length);
}

void MarstekPacketReader::reset() {
    _position = 0;
    _error = false;
    _errorString.clear();
}

bool MarstekPacketReader::require(qsizetype length) {
    if (length < 0) {
        _error = true;
        _errorString = QStringLiteral("Negative length.");
        return false;
    }
    if (_position + length > _buffer.size()) {
        _error = true;
        _errorString = QStringLiteral("Unexpected end of packet.");
        return false;
    }
    return true;
}

quint8 MarstekPacketReader::readUInt8() {
    if (!require(1))
        return 0;
    return static_cast<quint8>(_buffer[_position++]);
}

qint8 MarstekPacketReader::readInt8() {
    return static_cast<qint8>(readUInt8());
}

quint16 MarstekPacketReader::readUInt16BE() {
    if (!require(sizeof(quint16)))
        return 0;
    const quint16 value = qFromBigEndian<quint16>(reinterpret_cast<const uchar*>(_buffer.data() + _position));
    _position += sizeof(quint16);
    return value;
}

quint16 MarstekPacketReader::readUInt16LE() {
    if (!require(sizeof(quint16)))
        return 0;
    const quint16 value = qFromLittleEndian<quint16>(reinterpret_cast<const uchar*>(_buffer.data() + _position));
    _position += sizeof(quint16);
    return value;
}

qint16 MarstekPacketReader::readInt16BE() {
    return static_cast<qint16>(readUInt16BE());
}

qint16 MarstekPacketReader::readInt16LE() {
    return static_cast<qint16>(readUInt16LE());
}

quint32 MarstekPacketReader::readUInt32BE() {
    if (!require(sizeof(quint32)))
        return 0;
    const quint32 value = qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(_buffer.data() + _position));
    _position += sizeof(quint32);
    return value;
}

quint32 MarstekPacketReader::readUInt32LE() {
    if (!require(sizeof(quint32)))
        return 0;
    const quint32 value = qFromLittleEndian<quint32>(reinterpret_cast<const uchar*>(_buffer.data() + _position));
    _position += sizeof(quint32);
    return value;
}

qint32 MarstekPacketReader::readInt32BE() {
    return static_cast<qint32>(readUInt32BE());
}

qint32 MarstekPacketReader::readInt32LE() {
    return static_cast<qint32>(readUInt32LE());
}

quint64 MarstekPacketReader::readUInt64BE() {
    if (!require(sizeof(quint64)))
        return 0;
    const quint64 value = qFromBigEndian<quint64>(reinterpret_cast<const uchar *>(_buffer.data() + _position));
    _position += sizeof(quint64);
    return value;
}

quint64 MarstekPacketReader::readUInt64LE() {
    if (!require(sizeof(quint64)))
        return 0;
    const quint64 value = qFromLittleEndian<quint64>(reinterpret_cast<const uchar*>(_buffer.data() + _position));
    _position += sizeof(quint64);
    return value;
}

QByteArray MarstekPacketReader::readBytes(qsizetype length)  {
    if (!require(length))
        return {};
    QByteArray result(_buffer.data() + _position, length);
    _position += length;
    return result;
}

QByteArrayView MarstekPacketReader::readView(qsizetype length) {
    if (!require(length))
        return {};
    QByteArrayView result(_buffer.data() + _position, length);
    _position += length;
    return result;
}

QString MarstekPacketReader::readString(qsizetype length, QStringConverter::Encoding encoding) {
    const QByteArrayView view = readView(length);
    if (hasError())
        return {};
    switch (encoding) {
        case QStringConverter::Latin1:
            return QString::fromLatin1(view);
        case QStringConverter::Utf8:
        default:
            return QString::fromUtf8(view);
    }
}

} // namespace QtMarstek
