#ifndef _GPXE_SPI_BIT_H
#define _GPXE_SPI_BIT_H

/** @file
 *
 * SPI bit-bashing interface
 *
 */

#include <gpxe/spi.h>

/** A bit-bashing SPI bus */
struct spi_bit_basher {
	/** SPI bus */
	struct spi_bus bus;
	/** Bit-bashing interface */
	struct bit_basher basher;
};

/** Bit indices used for SPI bit-bashing interface */
enum {
	/** Serial clock */
	SPI_BIT_SCLK = 0,
	/** Master Out Slave In */
	SPI_BIT_MOSI,
	/** Master In Slave Out */
	SPI_BIT_MISO,
	/** Slave 0 select */
	SPI_BIT_SS0,
};

/**
 * Determine bit index for a particular slave
 *
 * @v slave		Slave number
 * @ret index		Bit index (i.e. SPI_BIT_SSN, where N=slave) 
 */
#define SPI_BIT_SS( slave ) ( SPI_BIT_SS0 + (slave) )

/** Delay between SCLK transitions */
#define SPI_BIT_UDELAY 1

extern void init_spi_bit_basher ( struct spi_bit_basher *spibit );

#endif /* _GPXE_SPI_BIT_H */
