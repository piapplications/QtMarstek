#ifndef MARSTEKTRANSPORT_H
#define MARSTEKTRANSPORT_H
#pragma once

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDateTime>
#include <QElapsedTimer>
#include "MarstekDatagram.h"

/**
 * @brief Internal UDP transport layer.
 *
 * This class is not part of the public API.
 * It only receives UDP datagrams and forwards them
 * to the protocol layer.
 */
class MarstekTransport : public QObject {
    Q_OBJECT

public:
    explicit MarstekTransport(QObject *parent = nullptr);
    ~MarstekTransport() override = default;

    bool start(quint16 port);
    void stop();
    bool isRunning() const;

signals:
    void datagramReceived(const MarstekDatagram& datagram);
    void errorOccurred(const QString &message);

private slots:
    void onReadyRead();

private:
    QElapsedTimer _timer;
    QUdpSocket _socket;
    bool _running = false;
};

#endif // MARSTEKTRANSPORT_H