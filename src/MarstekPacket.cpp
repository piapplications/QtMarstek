#include "MarstekPacket.h"
#include <QtEndian>

MarstekPacket::MarstekPacket(const QByteArray &data) {
    _data = data;
}

bool MarstekPacket::isEmpty() const {
    return _data.isEmpty();
}

int MarstekPacket::size() const {
    return _data.size();
}

const QByteArray &MarstekPacket::data() const {
    return _data;
}

QByteArray& MarstekPacket::data() {
    return _data;
}

void MarstekPacket::clear() {
    _data.clear();
}

quint8 MarstekPacket::at(int offset) const {
    if (offset < 0 || offset >= _data.size())
        return 0;
    return static_cast<quint8>(_data[offset]);
}

quint16 MarstekPacket::readUInt16BE(int offset) const {
    if (offset + 2 > _data.size())
        return 0;
    return qFromBigEndian<quint16>(reinterpret_cast<const uchar*>(_data.constData() + offset));
}

quint32 MarstekPacket::readUInt32BE(int offset) const {
    if (offset + 4 > _data.size())
        return 0;
    return qFromBigEndian<quint32>(reinterpret_cast<const uchar*>(_data.constData() + offset));
}

void MarstekPacket::append(quint8 value) {
    _data.append(static_cast<char>(value));
}

void MarstekPacket::append(quint16 value) {
    quint16 be = qToBigEndian(value);
    _data.append(reinterpret_cast<const char*>(&be), sizeof(be));
}

void MarstekPacket::append(quint32 value) {
    quint32 be = qToBigEndian(value);
    _data.append(reinterpret_cast<const char*>(&be), sizeof(be));
}

void MarstekPacket::append(const QByteArray &data) {
    _data.append(data);
}