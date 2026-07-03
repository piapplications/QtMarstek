#ifndef MARSTEKDEVICEINFO_H
#define MARSTEKDEVICEINFO_H

#include <optional>
#include <QString>
#include <QHostAddress>

namespace QtMarstek {

    /**
     * @brief DeviceInfo Un objet de cette classe donne des informatiuoins sur le périphérique distant.
     */
    class DeviceInfo {
        public:
            DeviceInfo() = default;
            [[nodiscard]] bool isValid() const;
            [[nodiscard]] const QString& device() const;
            void setDevice(const QString& device);
            [[nodiscard]] int version() const;
            void setVersion(int version);
            [[nodiscard]] const QString& bleMac() const;
            void setBleMac(const QString& mac);
            [[nodiscard]] const QString& wifiMac() const;
            void setWifiMac(const QString& mac);
            [[nodiscard]] const QString& wifiName() const;
            void setWifiName(const QString& name);
            [[nodiscard]] const QHostAddress& ip() const;
            void setIp(const QHostAddress& ip);

            static std::optional<DeviceInfo> fromJson(const QJsonObject& json);

        private:
            /**
             * @brief _device Identifiant du périphérique.
             */
            QString _device;
            /**
             * @brief _version Version du périphérique.
             */
            int _version = 0;
            /**
             * @brief _bleMac Identifiant Bluetooth du périphérique.
             */
            QString _bleMac;
            /**
             * @brief _wifiMac Adresse MAC WiFi du périphérique.
             */
            QString _wifiMac;
            /**
             * @brief _wifiName SSID du réseau WiFi.
             */
            QString _wifiName;
            /**
             * @brief _ip Adresse IP du périphérique.
             */
            QHostAddress _ip;
    };
}

#endif // MARSTEKDEVICEINFO_H