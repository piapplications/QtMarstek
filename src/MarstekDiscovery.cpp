#include "MarstekDiscovery.h"
#include "MarstekDevice.h"
#include "MarstekTransport.h"

namespace QtMarstek {

    static constexpr quint16 DiscoveryPort = 12345;   // à déplacer plus tard

    MarstekDiscovery::MarstekDiscovery(QObject* pParent) : QObject(pParent){
        _upD = std::make_unique<MarstekDiscoveryPrivate>();
        _upD->transport.setParent(this);
        connect(&_upD->transport, &MarstekTransport::datagramReceived,
                &_upD->protocol, &MarstekProtocol::processDatagram);
        connect(&_upD->protocol, &MarstekProtocol::discoveryReceived, this, &MarstekDiscovery::onDiscoveryReceived);
    }

    bool MarstekDiscovery::start() {
        return _upD->transport.start(DiscoveryPort);
    }

    void MarstekDiscovery::stop() {
        _upD->transport.stop();
    }

    QList<MarstekDevice*> MarstekDiscovery::devices() const {
        return _upD->devices.values();
    }

    MarstekDevice* MarstekDiscovery::device(const QHostAddress& address) const {
        return _upD->devices.value(address, nullptr);
    }

    //==================== SLOTS =======================================================================================

    void MarstekDiscovery::onDiscoveryReceived(const MarstekDiscoveryInfo& info) {
        auto it = _upD->devices.find(info.ipAddress);
        if (it == _upD->devices.end()) {
            auto* pDevice = new MarstekDevice(this);
            _upD->devices.insert(info.ipAddress, pDevice);
            emit deviceAdded(pDevice);
        }
        MarstekDevice* pDevice = _upD->devices.value(info.ipAddress);
        pDevice->setIpAddress(info.ipAddress);
        pDevice->setName(info.name);
        pDevice->setModel(info.model);
        pDevice->setFirmwareVersion(info.firmwareVersion);
        pDevice->setMacAddress(info.macAddress);
        _upD->devices.insert(info.ipAddress, pDevice);
        emit deviceAdded(pDevice);
    }

}