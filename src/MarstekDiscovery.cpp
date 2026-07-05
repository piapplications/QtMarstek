#include "MarstekDiscovery.h"
#include "MarstekDiscoveryInfo.h"
#include "MarstekDevice.h"
#include "MarstekTransport.h"
#include "MarstekProtocol.h"

namespace QtMarstek {

    static constexpr quint16 DiscoveryPort = 12345;   // à déplacer plus tard

    class MarstekDiscoveryPrivate {
        public:
            MarstekTransport transport;
            MarstekProtocol protocol;
            QHash<QHostAddress, MarstekDevice*> devices;
            MarstekDiscovery* q;

            explicit MarstekDiscoveryPrivate(MarstekDiscovery* pOwner) {
                q = pOwner;
            }

            void handleDiscovery(const MarstekDiscoveryInfo& info);
    };

    void MarstekDiscoveryPrivate::handleDiscovery(const MarstekDiscoveryInfo& info) {
        MarstekDevice* pDevice = devices.value(info.ipAddress, nullptr);
        if (!pDevice) {
            pDevice = new MarstekDevice(q);
            devices.insert(info.ipAddress, pDevice);
            pDevice->setIpAddress(info.ipAddress);
            emit q->deviceAdded(pDevice);
        }
        pDevice->setName(info.name);
        pDevice->setModel(info.model);
        pDevice->setFirmwareVersion(info.firmwareVersion);
        pDevice->setMacAddress(info.macAddress);
    }

    MarstekDiscovery::~MarstekDiscovery() = default;

    MarstekDiscovery::MarstekDiscovery(QObject* pParent) : QObject(pParent){
        _upD = std::make_unique<MarstekDiscoveryPrivate>(this);
        _upD->transport.setParent(this);
        _upD->protocol.setParent(this);
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

    void MarstekDiscovery::updateDevice(const MarstekDiscoveryInfo& info) {
        _upD->handleDiscovery(info);
    }

    //==================== SLOTS =======================================================================================

    void MarstekDiscovery::onDiscoveryReceived(const MarstekDiscoveryInfo& info) {
        updateDevice(info);
    }

}