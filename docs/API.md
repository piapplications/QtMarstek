# QtMarstek API Guide

Ce document présente l'utilisation de QtMarstek au travers d'exemples.

Pour la documentation détaillée de chaque classe, consulter la documentation Doxygen.

# Initialisation

#include <QtMarstek/MarstekDiscovery>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    MarstekDiscovery discovery;
    discovery.start();
    return app.exec();
}

---

# Découverte automatique

MarstekDiscovery discovery;

connect(&discovery,
        &MarstekDiscovery::deviceAdded,
        [](MarstekDevice *device) {
    qDebug() << device->name();
});
discovery.start();

---

# Liste des batteries


for (auto device : discovery.devices()) {
    qDebug() << device->name();
}

---

# Rafraîchir les informations

device->refresh();

Signal :

connect(device,
        &MarstekDevice::statusUpdated,
        ...);

---

# Lire les informations

qDebug() << device->name();
qDebug() << device->model();
qDebug() << device->firmwareVersion();
qDebug() << device->ipAddress();

---

# Lire l'état

qDebug() << device->stateOfCharge();
qDebug() << device->batteryPower();
qDebug() << device->pvPower();
qDebug() << device->gridPower();

---

# Modifier la puissance

device->setOutputPower(800);

---

# Changer le mode

device->setWorkMode(
        MarstekDevice::ManualMode);

---

# Lire le planning

auto scheduler = device->scheduler();

for (const auto &slot : scheduler->slots()) {
    ...
}

---

# Modifier le planning

scheduler->clear();
scheduler->addCharge(...);
scheduler->addDischarge(...);
scheduler->upload();

---

# Détection des erreurs

connect(device,
        &MarstekDevice::errorOccurred,
        [](const MarstekError &error){
    qDebug() << error.message();
});

---

# Arrêt

discovery.stop();