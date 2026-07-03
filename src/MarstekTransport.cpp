#include "MarstekTransport.h"
#include <QNetworkDatagram>

MarstekTransport::MarstekTransport(QObject *parent) : QObject(parent) {
    _timer.start();
    connect(&_socket, &QUdpSocket::readyRead, this, &MarstekTransport::onReadyRead);
    connect(&_socket, &QUdpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        emit errorOccurred(_socket.errorString());
    });
}

bool MarstekTransport::start(quint16 port) {
    if (_running)
        return true;
    constexpr auto flags = QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint;
    if (!_socket.bind(QHostAddress::AnyIPv4, port, flags)) {
        emit errorOccurred(_socket.errorString());
        return false;
    }
    _running = true;
    return true;
}

void MarstekTransport::stop() {
    if (!_running)
        return;
    _socket.close();
    _running = false;
}

bool MarstekTransport::isRunning() const {
    return _running;
}

void MarstekTransport::onReadyRead() {
    while (_socket.hasPendingDatagrams()) {
        QNetworkDatagram udp = _socket.receiveDatagram();
        MarstekDatagram datagram;
        datagram.data = udp.data();
        datagram.sender = udp.senderAddress();
        datagram.senderPort = udp.senderPort();
        datagram.timestampUtc = QDateTime::currentDateTimeUtc();
        datagram.monotonicMs = _timer.elapsed();
        emit datagramReceived(datagram);
    }
}
