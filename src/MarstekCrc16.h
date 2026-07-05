#ifndef MARSTEKCRC16_H
#define MARSTEKCRC16_H

#pragma once

#include <QByteArrayView>

namespace QtMarstek {

    /**
     * @brief Generic CRC-16 calculator.
     *
     * The algorithm parameters (polynomial, initial value, etc.)
     * will be finalized once the Marstek protocol has been fully
     * reverse engineered.
     */
    class MarstekCrc16 {
        public:
            /**
             * @brief Computes the CRC-16 of a memory buffer.
             * @param data Buffer to process.
             * @param polynomial CRC polynomial.
             * @param initial Initial CRC value.
             * @return Computed CRC.
             */
            static quint16 compute(QByteArrayView data, quint16 polynomial = 0x1021, quint16 initial = 0xFFFF);

        private:
            /**
             * @brief MarstekCrc16 Deleting of default constructor.
             */
            MarstekCrc16() = delete;
    };

} // namespace QtMarstek

#endif // MARSTEKCRC16_H
