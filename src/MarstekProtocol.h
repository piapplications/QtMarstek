#ifndef MARSTEKPROTOCOL_H
#define MARSTEKPROTOCOL_H
#pragma once

#include <QObject>
#include "MarstekDatagram.h"
#include "MarstekDiscoveryInfo.h"

/**
 * @brief Internal protocol decoder.
 *
 * This class converts raw UDP datagrams into high-level events.
 */
class MarstekProtocol : public QObject {
        Q_OBJECT

    public:
        explicit MarstekProtocol(QObject* pParent = nullptr);
        ~MarstekProtocol() override = default;

    public slots:
        void processDatagram(const MarstekDatagram& datagram);

    signals:
        void discoveryReceived(const MarstekDiscoveryInfo& info);
};

#endif // MARSTEKPROTOCOL_H
