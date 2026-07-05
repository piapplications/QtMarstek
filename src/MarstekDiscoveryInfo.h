#ifndef MARSTEKDISCOVERYINFO_H
#define MARSTEKDISCOVERYINFO_H

#pragma once

#include <QString>
#include <QHostAddress>

struct MarstekDiscoveryInfo {
    QString name;
    QString model;
    QString firmwareVersion;
    QString macAddress;
    QHostAddress ipAddress;
};
Q_DECLARE_METATYPE(MarstekDiscoveryInfo)

#endif // MARSTEKDISCOVERYINFO_H
