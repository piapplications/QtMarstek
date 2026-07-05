#ifndef MARSTEKPACKETREADER_H
#define MARSTEKPACKETREADER_H
#pragma once

#include <QByteArray>
#include <QByteArrayView>
#include <QString>
#include <QStringConverter>

namespace QtMarstek {

    /**
     * @brief The MarstekPacketReader class manages Marstek packet reading.
     */
    class MarstekPacketReader {
        public:
            explicit MarstekPacketReader(QByteArrayView buffer);

            [[nodiscard]]
            bool atEnd() const;
            [[nodiscard]]
            bool hasError() const;
            [[nodiscard]]
            QString errorString() const;
            [[nodiscard]]
            qsizetype size() const;
            [[nodiscard]]
            qsizetype position() const;
            [[nodiscard]]
            qsizetype remaining() const;
            [[nodiscard]]
            QByteArrayView buffer() const;
            [[nodiscard]]
            bool seek(qsizetype position);
            [[nodiscard]]
            bool skip(qsizetype length);
            quint8 readUInt8();
            qint8 readInt8();
            quint16 readUInt16BE();
            quint16 readUInt16LE();
            qint16 readInt16BE();
            qint16 readInt16LE();
            quint32 readUInt32BE();
            quint32 readUInt32LE();
            qint32 readInt32BE();
            qint32 readInt32LE();
            quint64 readUInt64BE();
            quint64 readUInt64LE();
            QByteArray readBytes(qsizetype length);
            QByteArrayView readView(qsizetype length);
            QString readString(qsizetype length, QStringConverter::Encoding encoding = QStringConverter::Utf8);
            void reset();

        private:
            bool require(qsizetype length);

        private:
            QByteArrayView _buffer;
            qsizetype _position = 0;
            bool _error = false;
            QString _errorString;
    };

} // namespace QtMarstek

#endif // MARSTEKPACKETREADER_H
