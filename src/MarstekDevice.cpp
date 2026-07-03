#include "MarstekDevice.h"

namespace QtMarstek {

    MarstekDevice::MarstekDevice(QObject* pParent) : QObject(pParent) {
    }

    QString MarstekDevice::name() const {
        return _name;
    }

    QString MarstekDevice::model() const {
        return _model;
    }

    QString MarstekDevice::firmwareVersion() const {
        return _firmwareVersion;
    }

    QString MarstekDevice::macAddress() const {
        return _macAddress;
    }

    QHostAddress MarstekDevice::ipAddress() const {
        return _ipAddress;
    }

    void MarstekDevice::setName(const QString &name){
        if (_name == name)
            return;
        _name = name;
        emit deviceChanged();
    }

    void MarstekDevice::setModel(const QString &model) {
        if (_model == model)
            return;
        _model = model;
        emit deviceChanged();
    }

    void MarstekDevice::setFirmwareVersion(const QString &version) {
        if (_firmwareVersion == version)
            return;
        _firmwareVersion = version;
        emit deviceChanged();
    }

    void MarstekDevice::setMacAddress(const QString &mac) {
        if (_macAddress == mac)
            return;
        _macAddress = mac;
        emit deviceChanged();
    }

    void MarstekDevice::setIpAddress(const QHostAddress &address) {
        if (_ipAddress == address)
            return;
        _ipAddress = address;
        emit deviceChanged();
    }

} // namespace QtMarstek