#include "DeviceInfo.h"
#include <QJsonObject>

namespace QtMarstek {

    /**
     * @brief DeviceInfo::isValid Lecture de l'état de l'indicateur de validité de l'objet d'information du
     * périphérique.
     * @return Etat de l'indicateur de validité de l'objet d'information du périphérique.
     */
    [[nodiscard]] bool DeviceInfo::isValid() const {
        return !_ip.isNull() && !_device.isEmpty();
    }

    /**
     * @brief DeviceInfo::device Lecture du nom du péripĥérique.
     * @return Nom du péripĥérique.
     */
    [[nodiscard]] const QString& DeviceInfo::device() const {
        return _device;
    }

    /**
     * @brief DeviceInfo::setDevice Mise à jour du nom du périphérique.
     * @param device Nom du péripĥérique.
     */
    void DeviceInfo::setDevice(const QString& device) {
        _device = device;
    }

    /**
     * @brief DeviceInfo::version Lecture de la version du périphérique.
     * @return Version du périphérique.
     */
    [[nodiscard]] int DeviceInfo::version() const {
        return _version;
    }

    /**
     * @brief DeviceInfo::setVersion Mise à jour de la version du périphérique.
     * @param version Version du périphérique.
     */
    void DeviceInfo::setVersion(int version) {
        _version = version;
    }

    /**
     * @brief DeviceInfo::bleMac Lecture de l'identifiant Bluetooth du périphérique.
     * @return Identifiant Bluetooth du périphérique.
     */
    [[nodiscard]] const QString& DeviceInfo::bleMac() const {
        return _bleMac;
    }

    /**
     * @brief DeviceInfo::setBleMac Mise à jour de l'identifiant Bluetooth du périphérique.
     * @param mac Identifiant Bluetooth du périphérique.
     */
    void DeviceInfo::setBleMac(const QString& mac) {
        _bleMac = mac;
    }

    /**
     * @brief DeviceInfo::wifiMac Lecture de l'adresse MAC WiFi du périphérique.
     * @return Adresse MAC WiFi du périphérique.
     */
    [[nodiscard]] const QString& DeviceInfo::wifiMac() const {
        return _wifiMac;
    }

    /**
     * @brief DeviceInfo::setWifiMac Mise à jour de de l'adresse MAC WiFi du périphérique.
     * @param mac Adresse MAC WiFi du périphérique.
     */
    void DeviceInfo::setWifiMac(const QString& mac) {
        _wifiMac = mac;
    }

    /**
     * @brief DeviceInfo::wifiName Lecture de l'identifiant du réseau WiFi utilisé par le périphérique.
     * @return Identifiant du réseau WiFi utilisé par le périphérique.
     */
    [[nodiscard]] const QString& DeviceInfo::wifiName() const {
        return _wifiName;
    }

    /**
     * @brief DeviceInfo::setWifiName Mise à jour de l'identifiant du réseau WiFi utilisé par le périphérique.
     * @param name Identifiant du réseau WiFi utilisé par le périphérique.
     */
    void DeviceInfo::setWifiName(const QString& name) {
        _wifiName = name;
    }

    /**
     * @brief DeviceInfo::ip Lecture de l'adresse IP du périphérique.
     * @return Adresse IP du périphérique.
     */
    [[nodiscard]] const QHostAddress& DeviceInfo::ip() const {
        return _ip;
    }

    /**
     * @brief DeviceInfo::setIp Mise à jour de l'adresse IP du périphérique.
     * @param ip Adresse IP du périphérique.
     */
    void DeviceInfo::setIp(const QHostAddress& ip) {
        _ip = ip;
    }

    /**
     * @brief DeviceInfo::fromJson {static }Transformation d'un flux JSON de la réponse à une demande d'information du
     * périphérique.
     * @param json Flux JSON de la réponse.
     * @return Objet donnant des informations sur le périphérique.
     */
    std::optional<DeviceInfo> DeviceInfo::fromJson(const QJsonObject& json) {
        DeviceInfo info;
        QString device = "?";
        QString property = "device";
        if (json.contains(property) && json[property].isString())
            device = json[property].toString();
        info.setDevice(device);
        int version = -1;
        property = "ver";
        if (json.contains(property) && json[property].isDouble())
            version = json[property].toInt();
        info.setVersion(version);
        QString bleMac = "?";
        property = "ble_mac";
        if (json.contains(property) && json[property].isString())
            bleMac = json[property].toString();
        info.setBleMac(bleMac);
        QString wifiMac = "?";
        property = "wifi_mac";
        if (json.contains(property) && json[property].isString())
            wifiMac = json[property].toString();
        info.setWifiMac(wifiMac);
        QString wifiName = "?";
        property = "wifi_name";
        if (json.contains(property) && json[property].isString())
            wifiName = json[property].toString();
        info.setWifiMac(wifiName);
        QHostAddress ip = QHostAddress();
        QString s;
        if (json.contains(property) && json[property].isString())
            s = json[property].toString();
        QHostAddress addr = QHostAddress(s);
        if (!addr.isNull())
            ip = addr;
        info.setIp(ip);
        return info;
    }
}
