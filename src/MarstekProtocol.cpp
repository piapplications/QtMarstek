#include "MarstekProtocol.h"

MarstekProtocol::MarstekProtocol(QObject *pParent) : QObject(pParent) {
}

void MarstekProtocol::processDatagram(const MarstekDatagram& datagram) {
    //
    // QTM-001
    //
    // Aucun décodage réel pour le moment.
    // Nous créons simplement une structure minimale
    // permettant à MarstekDiscovery de fonctionner.
    //
    MarstekDiscoveryInfo info;
    info.ipAddress = datagram.sender;
    info.name = QStringLiteral("Unknown");
    info.model = QStringLiteral("Unknown");
    info.firmwareVersion.clear();
    info.macAddress.clear();
    emit discoveryReceived(info);
}
