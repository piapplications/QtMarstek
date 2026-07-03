#ifndef JSONRPCUTILS_H
#define JSONRPCUTILS_H

#pragma once

#include <QByteArray>
#include <QJsonObject>
#include <QString>

namespace QtMarstek {

    namespace JsonRpc {
        QByteArray createRequest(int id, const QString& method, const QJsonObject& params = {});
        bool parseResponse(const QByteArray& data, QJsonObject& response);
    } // namespace JsonRpc

} // namespace QtMarstek

#endif // JSONRPCUTILS_H
