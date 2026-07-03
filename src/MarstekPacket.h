#ifndef MARSTEKPACKET_H
#define MARSTEKPACKET_H

#pragma once

#include <QByteArray>

/**
 * @brief Represents a raw Marstek protocol packet.
 *
 * This class does not interpret the packet contents.
 * Parsing is performed by MarstekProtocol.
 */
class MarstekPacket {
    public:
        MarstekPacket() = default;
        explicit MarstekPacket(const QByteArray &data);
        bool isEmpty() const;
        int size() const;
        const QByteArray &data() const;
        QByteArray& data();
        void clear();
        quint8 at(int offset) const;
        quint16 readUInt16BE(int offset) const;
        quint32 readUInt32BE(int offset) const;
        void append(quint8 value);
        void append(quint16 value);
        void append(quint32 value);
        void append(const QByteArray &data);

    private:
        QByteArray _data;
};

#endif // MARSTEKPACKET_H
