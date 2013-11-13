#!/bin/bash

cd src &&  make bin/undionly.kpxe EMBED=bootstrap.ipxe  && echo "Your file is at bin/undionly.kpxe"
