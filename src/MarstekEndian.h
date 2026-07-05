#ifndef MARSTEKENDIAN_H
#define MARSTEKENDIAN_H
#pragma once

#include <QtEndian>

namespace QtMarstek::Endian {

    template<typename T>
    inline T readBig(const void *pData) {
        return qFromBigEndian<T>(reinterpret_cast<const uchar*>(pData));
    }

    template<typename T>
    inline T readLittle(const void* pData) {
        return qFromLittleEndian<T>(reinterpret_cast<const uchar*>(pData));
    }

    template<typename T>
    inline void writeBig(void* pData, T value) {
        qToBigEndian<T>(value, reinterpret_cast<uchar*>(pData));
    }

    template<typename T>
    inline void writeLittle(void *pData, T value) {
        qToLittleEndian<T>(value, reinterpret_cast<uchar*>(pData));
    }

} // namespace QtMarstek::Endian

#endif // MARSTEKENDIAN_H
