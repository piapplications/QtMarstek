#include <QCoreApplication>
#include <QDebug>

#include <MarstekDiscovery.h>
#include <MarstekDevice.h>

using namespace QtMarstek;

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    qInfo() << "Exemple Console QtMarstek";
    qInfo() << "Recherche des périphériques...";
    qInfo();
    MarstekDiscovery discovery;
    QObject::connect(&discovery, &MarstekDiscovery::deviceAdded, [](MarstekDevice* pDevice) {
        qInfo().noquote() << "----------------------------------------";
        qInfo() << "Périphérique découvert";
        qInfo() << "     Nom :" << pDevice->name();
        qInfo() << "  Modèle :" << pDevice->model();
        qInfo() << "Firmware :" << pDevice->firmwareVersion();
        qInfo() << "     MAC :" << pDevice->macAddress();
        qInfo() << "      IP :" << pDevice->ipAddress().toString();
        qInfo().noquote() << "----------------------------------------";
        qInfo();
    });
    QObject::connect(&discovery, &MarstekDiscovery::deviceRemoved, [](MarstekDevice* pDevice) {
        qInfo() << "Périphérique supprimé :" << pDevice->ipAddress().toString();
    });
    if (!discovery.start()) {
        qCritical() << "Echec du démarrage de la découverte.";
        return EXIT_FAILURE;
    }
    return app.exec();
}
