#ifndef MARSTEKDEVICE_H
#define MARSTEKDEVICE_H
#pragma once

#include <QObject>
#include <QHostAddress>
#include <QDateTime>

namespace QtMarstek {

    class MarstekScheduler;

    /**
     * @brief Represents a Marstek battery discovered on the network.
     *
     * This class exposes the public state of a battery.
     * Communication with the device is entirely managed by the library.
     */
    class MarstekDevice : public QObject {
        Q_OBJECT

        Q_PROPERTY(QString name READ name NOTIFY deviceChanged)
        Q_PROPERTY(QString model READ model NOTIFY deviceChanged)
        Q_PROPERTY(QString firmwareVersion READ firmwareVersion NOTIFY deviceChanged)
        Q_PROPERTY(QString macAddress READ macAddress NOTIFY deviceChanged)
        Q_PROPERTY(QHostAddress ipAddress READ ipAddress NOTIFY deviceChanged)

    public:
        explicit MarstekDevice(QObject* pParent = nullptr);
        ~MarstekDevice() override = default;

        QString name() const;
        QString model() const;
        QString firmwareVersion() const;
        QString macAddress() const;
        QHostAddress ipAddress() const;

    signals:
        void deviceChanged();

    private:
        friend class MarstekDiscovery;
        friend class MarstekDiscoveryPrivate;
        friend class MarstekProtocol;

        void setName(const QString &name);
        void setModel(const QString &model);
        void setFirmwareVersion(const QString &version);
        void setMacAddress(const QString &mac);
        void setIpAddress(const QHostAddress &address);

    private:
        QString _name;
        QString _model;
        QString _firmwareVersion;
        QString _macAddress;
        QHostAddress _ipAddress;
    };

} // namespace QtMarstek

#endif // MARSTEKDEVICE_H
