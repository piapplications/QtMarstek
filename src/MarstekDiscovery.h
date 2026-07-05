#ifndef MARSTEKDISCOVERY_H
#define MARSTEKDISCOVERY_H
#pragma once

#include <QObject>
#include <QHash>
#include <QHostAddress>
#include "MarstekDiscoveryInfo.h"

namespace QtMarstek {

    class MarstekDevice;
    class MarstekDiscoveryPrivate;

    /**
     * @brief Discovers Marstek devices on the local network.
     */
    class MarstekDiscovery : public QObject {
        Q_OBJECT

    public:
        explicit MarstekDiscovery(QObject*  pParent = nullptr);
        ~MarstekDiscovery() override;

        bool start();
        void stop();
        QList<MarstekDevice*> devices() const;
        MarstekDevice* device(const QHostAddress &address) const;

    signals:
        void deviceAdded(QtMarstek::MarstekDevice* pDevice);
        void deviceRemoved(QtMarstek::MarstekDevice* pDevice);

    private slots:
        void onDiscoveryReceived(const MarstekDiscoveryInfo& info);

    private:
        void updateDevice(const MarstekDiscoveryInfo& info);

        Q_DISABLE_COPY_MOVE(MarstekDiscovery)
        std::unique_ptr<MarstekDiscoveryPrivate> _upD;
    };

}

#endif // MARSTEKDICOVERY_H
