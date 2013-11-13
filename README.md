# Overview

This is a fork of iPXE from http://git.ipxe.org/ipxe.git

We embed our own boot script, and change some timeout values.

This script is used to [chainload](http://ipxe.org/howto/chainloading) from stock PXE roms.

# Building

To build, just run ./build.sh from a sane build environment (os x will not work)

The output will be undionly.kpxe

# Usage

Just point your tftp server to use the undionly.kpxe and you should be good to go.

# Pointers

If you want to add additional info from the smbios, you need to do the following:

Determine the SMBIOS type ID:

* Run dmidecode, search for the attribute you want
* Look at the type id at the top, should look like: "Handle 0x0002, DMI type 2, 15 bytes"
* Create a struct corresponding to this object at "src/include/ipxe/smbios.h"
 * The ID you specify should be the id you got earlier, ie "2" for above example
 * The order of the fields in the struct MATTERS. 
  * Get a raw dmidecode dump, notice the order of strings in it - index these strings into the sruct in the same order. 
* Create an entry for your struct at src/interface/smbios/smbios\_settings.c
* The name you give it here is how you will access it through the command line via "show"
 * Use the symbol you defined earlier for the type
