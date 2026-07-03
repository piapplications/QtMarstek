#ifndef MARSTEKDATAGRAM_H
#define MARSTEKDATAGRAM_H

#include <QByteArray>
#include <QHostAddress>
#include <QDateTime>

/**
 * @brief The MarstekDatagram structure matches a Marstek datagram.
 */
struct MarstekDatagram {
    QByteArray data;
    QHostAddress sender;
    quint16 senderPort;
    QDateTime timestampUtc;
    qint64 monotonicMs;
};

#endif // MARSTEKDATAGRAM_H
