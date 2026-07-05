#ifndef MARSTEKPACKETWRITER_H
#define MARSTEKPACKETWRITER_H
#pragma once

#include <QByteArray>
#include <QByteArrayView>
#include <QString>
#include <QStringConverter>

namespace QtMarstek {

    /**
     * @brief The MarstekPacketWriter class creates Marstek packet datagram.
     */
    class MarstekPacketWriter {
        public:
            MarstekPacketWriter() = default;

            [[nodiscard]]
            bool hasError() const;
            [[nodiscard]]
            QString errorString() const;
            [[nodiscard]]
            qsizetype size() const;
            [[nodiscard]]
            bool isEmpty() const;
            [[nodiscard]]
            const QByteArray &buffer() const;
            void clear();
            void reserve(qsizetype size);
            void writeUInt8(quint8 value);
            void writeInt8(qint8 value);
            void writeUInt16BE(quint16 value);
            void writeUInt16LE(quint16 value);
            void writeInt16BE(qint16 value);
            void writeInt16LE(qint16 value);
            void writeUInt32BE(quint32 value);
            void writeUInt32LE(quint32 value);
            void writeInt32BE(qint32 value);
            void writeInt32LE(qint32 value);
            void writeUInt64BE(quint64 value);
            void writeUInt64LE(quint64 value);
            void writeBytes(QByteArrayView data);
            void writeString(const QString &value, QStringConverter::Encoding encoding = QStringConverter::Utf8);

        private:
            QByteArray _buffer;
            bool _error = false;
            QString _errorString;
    };

} // namespace QtMarstek
#endif // MARSTEKPACKETWRITER_H
