#pragma once

#include <QByteArray>
#include <QStringView>
#include <QString>

inline QByteArray fromHex(const QByteArray &text) {
    QByteArray hex(text);
    hex.replace(" ", "");
    return QByteArray::fromHex(hex);
}

inline QString toHex(QByteArrayView data) {
    return QString::fromLatin1(data.toByteArray().toHex(' '));
}
