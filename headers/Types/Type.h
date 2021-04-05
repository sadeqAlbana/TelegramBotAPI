#ifndef TYPE_H
#define TYPE_H

#include "TelegramAPI_global.h"

#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonValue"
#include "QJsonArray"
#include "QString"
#include "QDebug"

class Type
{
protected:
    QJsonObject _jsonObject;

public:
    template<typename T>
    QJsonArray QVectorToQJsonArray(QVector<T> jsonObjects)
    {
        QJsonArray tempJsonArray;

        for(int i = 0; i < jsonObjects.size(); i++)
            tempJsonArray.insert(tempJsonArray.end(), jsonObjects[i].toObject());

        return tempJsonArray;
    }

    template<typename T>
    QVector<T> QJsonArrayToQVector(QJsonArray jsonArray, T)
    {
        QVector<T> tempQVector;

        for(QJsonArray::const_iterator i = jsonArray.begin(); i != jsonArray.end(); i++)
            tempQVector.insert(tempQVector.end(), T(i->toObject()));

        return tempQVector;
    }

    /*template<typename T>
    QJsonArray toArray(QList<T> jsonObjects) // Takes QList of types (QList<User> or QList<Message>) and returnes JSON array with JSON objects of this types; // Переделать на qvector не помню почему раздуплить
    {
        QJsonArray tempJsonArray;

        for(int i = 0; i < jsonObjects.size(); i++)
            tempJsonArray.insert(0, jsonObjects[i].toObject());

        return tempJsonArray;
    }

    // Заменить на qVector Не помню почему раздуплить почему

    template<typename T>
    QList<T> toQList(QJsonArray jsonArray, T)
    {
        QList<T> tempQList;

        for(QJsonArray::const_iterator i = jsonArray.begin(); i != jsonArray.end(); i++)
            tempQList.insert(0, T(i->toObject()));

        return tempQList;
    }*/

    inline QJsonObject toObject() { return _jsonObject; } ; // Return a JSON object of class

    inline bool isEmpty() { return _jsonObject.isEmpty(); }
};

#endif // TYPE_H