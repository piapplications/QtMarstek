#include <QtTest>

#include "MarstekProtocol.h"
#include "MarstekDatagram.h"

class TestMarstekProtocol : public QObject {
        Q_OBJECT

    private slots:
        void discoverySignal();
};

void TestMarstekProtocol::discoverySignal() {
    MarstekProtocol protocol;
    QSignalSpy spy(&protocol, &MarstekProtocol::discoveryReceived);
    MarstekDatagram dg;
    dg.sender = QHostAddress("192.168.2.249");
    protocol.processDatagram(dg);
    QCOMPARE(spy.count(), 1);
    QList<QVariant> args = spy.takeFirst();
    auto info = qvariant_cast<MarstekDiscoveryInfo>(args.at(0));
    QCOMPARE(info.ipAddress, QHostAddress("192.168.2.249"));
    QCOMPARE(info.name, QStringLiteral("Unknown"));
    QCOMPARE(info.model, QStringLiteral("Unknown"));
}

QTEST_APPLESS_MAIN(TestMarstekProtocol)

#include "TestMarstekProtocol.moc"
