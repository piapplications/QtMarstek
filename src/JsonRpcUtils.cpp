#include "JsonRpcUtils.h"
namespace QtMarstek {
    namespace JsonRpc {

        /**
         * @brief createRequest Création de la requête JSON d'interrogation du périphérique.
         * @param id N° de périphérique.
         * @param method Fonction distante invoquée.
         * @param params Paramètres.
         * @return Contenu des données de la réponse UDP.
         */
        QByteArray createRequest(int id, const QString& method, const QJsonObject& params) {
            QJsonObject request;
            request["id"] = id;
            request["method"] = method;
            request["params"] = params;
            return QJsonDocument(request).toJson(QJsonDocument::Compact);
        }

        /**
         * @brief parseResponse Analyse de la réponse UDP à une requête JSON.
         * @param data Données de la réponse UDP.
         * @param response [out] Flux JSON de la réponse.
         * @return Statut de l'analyse (false indique un échec).
         */
        bool parseResponse(const QByteArray& data, QJsonObject& response) {
            QJsonParseError error;
            const QJsonDocument doc = QJsonDocument::fromJson(data, &error);
            if (error.error != QJsonParseError::NoError)
                return false;
            if (!doc.isObject())
                return false;
            response = doc.object();
            return true;
        }

    }
}